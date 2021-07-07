#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
        //program use. example
        if( argc<=1){
                printf("USE: ./program [host]\n");
                return 0;
        //case correct argc
        }else{
                struct hostent *target = gethostbyname(argv[1]);
                if(target == NULL){
                        printf("[!] ERROR [!]");
                }else{
                //decode inet_ntoa for ascii data encode
                //struct in address
                printf("IP: %s\n",inet_ntoa(*((struct in_addr *)target->h_addr)));
                }
        }
}
