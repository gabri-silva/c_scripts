#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]){
        int mysocket;
        int conect;

        int port;
        int init = 0;
        int final = 65535;
        char *destiny;
        destiny = argv[1];

        struct sockaddr_in target;

        for(port=init;port<=final;port++){
                mysocket = socket(AF_INET, SOCK_STREAM,0);
                target.sin_family = AF_INET;
                target.sin_port = htons(port);
                target.sin_addr.s_addr = inet_addr(destiny);

                conect = connect(mysocket, (struct sockaddr *)&target, sizeof target);
                if(conect == 0){
                        printf("Port: %d - status [+]OPEN\n",port);
                        close(mysocket);
                        close(conect);
                }else{
                        close(mysocket);
                        close(conect);
                }
        }
}
