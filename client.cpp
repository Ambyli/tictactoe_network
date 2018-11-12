#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

/* Error message response */
void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, response;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256]; //limits how much text can be sent to the server
    
    //too little arguments
    if (argc < 3) 
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //socket error
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]); //retrieve host address from argument

    //if no host address was given
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    //error connecting
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");


    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
   
    //write to server
    response = write(sockfd, buffer, strlen(buffer));

    //nothing written error
    if (response < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);

    //read from server
    response = read(sockfd,buffer,255);

    //nothing retrieved error
    if (response < 0) 
         error("ERROR reading from socket");

    //print response
    printf("%s\n",buffer);
    return 0;
}
