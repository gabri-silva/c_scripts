#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]){
        //set variables type
        int mysocket;
        int conect;

        int port;
        int init = 0;
        int final = 65535;
        char *destiny;
        destiny = argv[1];
        //scruct module construction
        struct sockaddr_in target;

        for(port=init;port<=final;port++){
                mysocket = socket(AF_INET, SOCK_STREAM,0);
                target.sin_family = AF_INET;
                target.sin_port = htons(port);
                target.sin_addr.s_addr = inet_addr(destiny);
                //connect socket in port and target for condition validate host
                conect = connect(mysocket, (struct sockaddr *)&target, sizeof target);
                //condition for connection == 0
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
