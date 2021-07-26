#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
namespace socketserver
{
    class server
    {

    public:
        server(char *, int, int);
        void acceptconnection();
        size_t read_some(char *, int);
        size_t write_some(char *, int);
       void  closeconnection();
    private:
        struct sockaddr_in main, peer;
        int mysocket, peersocket;
        socklen_t len = sizeof(peer);
    };

    server::server(char *host, int port, int nclients)
    {
        main.sin_family = AF_INET;
        main.sin_port = htons(port);
        main.sin_addr.s_addr = inet_addr(host);

        mysocket = socket(AF_INET, SOCK_STREAM, 0);
        bind(mysocket, (struct sockaddr *)&main, sizeof(main));
        listen(mysocket, nclients);
    };
    void server::acceptconnection()
    {
        peersocket = accept(mysocket, (struct sockaddr *)&peer, &len);
    }
    size_t server::write_some(char *data, int length)
    {
        return send(peersocket, data, len, 0);
    }
    size_t server::read_some(char *BUFFER, int len)
    {
        return recv(peersocket,BUFFER,len,0);
    }
    void server::closeconnection(){
        close(mysocket);
    }
}