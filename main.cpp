#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>

int main(){


    const char * message = "The path for python is closed! but C is here";

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    printf("%s\n",message);


    sockaddr_in myaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(12345);
    inet_pton(AF_INET,"100.82.203.223",&myaddr.sin_addr);
    for (int i = 0;i<100;i++){
        sendto(sockfd,message,strlen(message),0,(struct sockaddr*)&myaddr,sizeof(myaddr));
    }
}
