#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    
struct sockaddr_in in,in2;
in.sin_addr.s_addr = inet_addr("127.0.0.1");
in.sin_port= htons(8089);
in.sin_family=AF_INET;
  int opt = 1;
socklen_t len = sizeof(in2);
int socketx,new ;

if((socketx = socket(AF_INET,SOCK_STREAM,0)) <=0)
perror("error socket");
setsockopt(socketx, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt));
bind(socketx,( struct sockaddr*)&in,sizeof(in));
listen(socketx,4);

 new =accept(socketx,(struct sockaddr*)&in2,&len);
printf("accepted");
char * m="ahasbh";
// sendto(socketx,m,strlen(m),0,&in2,sizeof(in2));


int xd = send(new,m,strlen(m),0);
// // perror("cd");
//  printf("%ds",xd);}
listen(socketx,4);

 new =accept(socketx,(struct sockaddr*)&in2,&len);
printf("accepted");
close(socketx);
 
    return 0;
}
