/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

using namespace std;

#define MAXBUF 256 /* MAX I/O buffer size */
#define MAXLINE 256 /* Max text line length */
#define LISTENQ 5 /* Second argument to listen() */

/* Error message response */
void error(string msg)
{
  perror((char*)msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sockfd, newsockfd, portno, clilen;

  char buffer[MAXBUF]; //buffer for data to be sent or retrieved

  //structs for server, client, and socket
  struct sockaddr_in serv_addr, cli_addr;

  int response; //holds response success or failure determination value


  //not enough arguments provided
  if (argc < 2) 
  {
    fprintf(stderr,"ERROR, no port provided\n");
    return 1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //socket error
  if (sockfd < 0) 
    error("ERROR opening socket");


  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    error("ERROR on binding");

  //listen for client
  listen(sockfd, LISTENQ);

  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

  if (newsockfd < 0) 
    error("ERROR on accept");

  bzero(buffer, MAXBUF);

  response = fread(newsockfd, buffer, MAXBUF-1);
  if (response < 0) 
    error("ERROR reading from socket");

  printf("Here is the message: %s\n",buffer);

  response = fwrite(newsockfd,"I got your message",18);
  if (response < 0) 
    error("ERROR writing to socket");


  return 0; 
}
