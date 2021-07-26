#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
int main(int argc, char const *argv[])
{
struct sockaddr_in in,in2;
in.sin_addr.s_addr = inet_addr("127.0.0.1");
in.sin_port= htons(8089);
in.sin_family=AF_INET;


int socketx ;

if((socketx = socket(AF_INET,SOCK_STREAM,0)) <=0)
perror("error socket");

 if( connect(socketx,(const struct sockaddr*)&in,sizeof(in))<=0)perror("connect error");
// char b[30];
// int c = recv(socketx,b,30,0);
// printf("%s %d",b, c);
char *m="GET  / HTTP/";
 char b[3000];
int c = recv(socketx,b,3000,0);
printf("%s %d",b, c);
send(socketx,m,strlen(m),0);
close(socketx);
}