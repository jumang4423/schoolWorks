#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MYPORT "4567"                      // the port that client  will be connecting to
#define MAXBUFLEN 100
// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
  if (sa->sa_family == AF_INET) {
    return &(((struct sockaddr_in*)sa)->sin_addr);
  }
  return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main(void)
{
  int sockfd;
  struct addrinfo hints, *servinfo, *p;
  int rv;
  int numbytes;
  struct sockaddr_storage their_addr;
  char buf[MAXBUFLEN];
  int32_t receivedNumber;
  socklen_t addr_len;
  
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;             // set to AF_INET to force IPv4
  hints.ai_socktype = SOCK_DGRAM;          // UDP 
  hints.ai_flags = AI_PASSIVE;             // use my IP

 
  if ((rv = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }
  // loop through all the results and bind to the first we can
  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("server: socket");
      continue;
    }
    if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("server: bind");
      continue;
    }
    break;
  }
  if (p == NULL) {
    fprintf(stderr, "listener: failed to bind socket\n");
    exit(1);
  }
  printf("server: waiting for client...\n");
  addr_len = sizeof their_addr;

  //Receive from client
  if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0, (struct sockaddr *)&their_addr, &addr_len)) == -1) {
    perror("recvfrom");
    exit(1);
  }
  printf("Received from client: %s\n", buf);

  //Send client an ACK message

  /*
    Complete this part
  */
  
  freeaddrinfo(servinfo);
  close(sockfd);
  return 0;
}
