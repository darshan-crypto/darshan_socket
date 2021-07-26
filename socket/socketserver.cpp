#include"socketserver.h"

int main(int argc, char const *argv[])
{
    socketserver::server s("127.0.0.1",8089,10);
    s.acceptconnection();
    s.write_some("hello",5);
    char m[20];
    s.read_some(m,20);
    printf("%s",m);
    s.closeconnection();
    return 0;
}
