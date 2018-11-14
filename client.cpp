#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXBUF 256 /* MAX I/O buffer size */
#define MAXLINE 256 /* Max text line length */
#define LISTENQ 5 /* Second argument to listen() */

/* Error message response */
void error(char *msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sockfd, portno, response;

  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[MAXBUF]; //limits how much text can be sent to the server

  //too little arguments
  if (argc < 3) 
  {
    fprintf(stderr,"usage %s hostname port\n", argv[0]);
    return 0;
  }
  
  //get port number
  portno = atoi(argv[2]);
  //open socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //socket error
  if (sockfd < 0) 
    error("ERROR opening socket");

  //retrieve host address from argument
  server = gethostbyname(argv[1]);
  //if no host address was given
  if (server == NULL) 
  {
    fprintf(stderr,"ERROR, no such host\n");
    return 0;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;

  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

  serv_addr.sin_port = htons(portno);

  //error connecting
  if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
    error("ERROR connecting");


  printf("Please enter the message: ");
  bzero(buffer, MAXBUF);
  fgets(buffer, MAXBUF-1, stdin);

  //write to server
  response = write(sockfd, buffer, strlen(buffer));

  //nothing written error
  if (response < 0) 
    error("ERROR writing to socket");
  bzero(buffer, MAXBUF);

  //read from server
  response = read(sockfd, buffer, MAXBUF-1);

  //nothing retrieved error
  if (response < 0) 
    error("ERROR reading from socket");

  //print response
  printf("%s\n",buffer);
  return 0;
}
