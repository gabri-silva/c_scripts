#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){

        int iteration;
        char line;

        FILE *file;
        file = fopen(argv[2], "r");
        if(file == NULL){
                printf("[!] ERROR FILE [!]");
        }
        if(argc<=2){
                printf("|||||||||||||||||||||||||||||||||||||||");
                printf("|||||||||||||DNS RESOLVER||||||||||||||");
                printf("|||||||||||||||||1.1|||||||||||||||||||");
                printf("||use: ./program [host] [wordlist.txt]|");
                printf("||||||||||Z2FicmllbCBhbG1laWRh|||||||||");
                printf("|||||||||||||||||||||||||||||||||||||||");
        }else{
                for(iteration=1;iteration<=1024;iteration++){
                        struct hostent *target gethostbyname(argv[1]);
                        if(*target == NULL){
                                printf("[!] HOST OFFLINE [!]");
                        }else{
                        printf("HOST ONLINE: %s",inet_ntoa(*((struct in_addr *)target->h_addr)));
                        }
                }
        }
        return 0;
}

