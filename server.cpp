#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 100

int main(int argc, char *argv[])
{
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int sfd, s, len;
  struct sockaddr_storage peer_addr;
  socklen_t peer_addr_len;
  ssize_t nread;
  char buf[BUF_SIZE];
  string message = "";

  if (argc != 2) 
  {
    fprintf(stderr, "Usage: %s port\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;    //allow IPv4 or IPv6
  hints.ai_socktype = SOCK_DGRAM; //datagram socket
  hints.ai_flags = AI_PASSIVE;    //for wildcard IP address
  hints.ai_protocol = 0;          //any protocol
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  s = getaddrinfo(NULL, argv[1], &hints, &result);
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    exit(EXIT_FAILURE);
  }

  /* getaddrinfo() returns a list of address structures.
     Try each address until we successfully bind(2).
     If socket(2) (or bind(2)) fails, we (close the socket
     and) try the next address. */

  for (rp = result; rp != NULL; rp = rp->ai_next) 
  {
    sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1)
      continue;

    if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
      break; //bind success

    close(sfd);
  }

  if (rp == NULL) //No address succeeded
  {         
    fprintf(stderr, "Could not bind\n");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result); //No longer needed

  //main process
  while(true) 
  {
    peer_addr_len = sizeof(struct sockaddr_storage);
    nread = recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr *) &peer_addr, &peer_addr_len);
    if (nread == -1)
      continue; //Ignore failed request

    char host[NI_MAXHOST], service[NI_MAXSERV];

    s = getnameinfo((struct sockaddr *) &peer_addr, peer_addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICSERV);
    if (s == 0)
      printf("Received %ld bytes: %s\n", (long) nread, buf);
    else
      fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));

    //send response to client and check if ack failed to send
    while(true)
    {
      cout<<"Enter coordinate here: ";
      cin>>message;
      len = message.length() + 1; //+1 for terminating null byte, this is used only if message is a string
    
      if(len > 2) //2 refers to message size + 1 for null byte
      {
        fprintf(stderr, "Exceeding message limitations\n");
        continue;
      }
      break;
    }

    //send message
    if (sendto(sfd, message.c_str(), nread, 0, (struct sockaddr *) &peer_addr, peer_addr_len) != nread)
      fprintf(stderr, "Error sending response\n");
  }
}
