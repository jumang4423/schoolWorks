#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <openssl/sha.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "packet.h"
#include "helper_functions.c"

int main(int argc, char *argv[])
{
    // Data to send to client
    char *datamsg = (char *) malloc(sizeof datamsg);
 
    // The packet counter
    unsigned int packetcou = 1;

    // The result of the hash function
    char sha1_hash[20];
    char sha1_hash_str[20];
    SHA_CTX c;
    

    // Socket descriptor and additional variables for handling the connection
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv, numbytes;
    char *server_port;
    char *passwd;

    // Instance of the union packet and while-flag
    Packets packet;
    int quitFlag = 1;

    // Needed for the sendto() and recvfrom()
    struct sockaddr_storage their_addr;
    socklen_t addr_len = sizeof their_addr;

    // File to send
    char *fileIn;

    /*
    SETUP THE SOCKET CONNECTION,
    AND BE SURE THAT A CONNECTION IS ACTUALLY BEEN MADE.

    Hint: Use the methods getaddrinfo() socket() and bind()
    */

    /*
     COMMUNICATE WITH THE CLIENT,
     BE SURE TO HANDLE THE NETWORK BYTE ORDER

     Hint: Use the methods sendto(), recvfrom() and bzero()
    */

    if(argc != 4){
      printf("Not enough or too many arguments\n");
      exit(1);
    }
    server_port = argv[1];
    passwd      = argv[2];
    fileIn      = argv[3];
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE; 
  
    if ((rv = getaddrinfo(NULL, server_port, &hints, &servinfo)) != 0) {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
      return 1;
    }

    for(p = servinfo; p != NULL; p = p->ai_next) {
      if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
	perror("listener: socket");
	continue;
      }
    if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("listener: bind");
      continue;
    }
    break;
  }
  if (p == NULL) {
    fprintf(stderr, "listener: failed to bind socket\n");
    return 2;
  }
  printf("Waiting for download...\n");
  addr_len = sizeof their_addr;

  
  while(quitFlag){

    // Receiving a packet from client and processing it
    
    /* Complete this part */
    
    switch(ntohs(packet.ctrl_msg.header)){ // Check the header
    case JOIN_REQ:                         // Receive JOIN_REQ packet from client. Send PASS_REQ to client
      /* Complete this part */
      break;
    case PASS_RESP:                        // Receive PASS_RESP_PACKET to client.
      if(packetcou <= 3){
	if(strcmp(packet.pass_resp.password, passwd) == 0){  //passwd is correct
	  // Send a ACCEPT packet
	  /* Complete this part */
	  
	  // Read data from txt file (test.txt) and Send it
	  /* Complete this part */
	  
	  // Calculate SHA1-Digest of the data 
	  /* Complete this part */

	  for(int i = 0; i < sizeof(sha1_hash); i++)        //Convert 20 byte Hex values sha1_hash to string sha1_hash_str
	    sprintf(sha1_hash_str+(i*2), "%02x", sha1_hash[i]);	

	  strcpy(packet.terminate.digest, sha1_hash_str);

	  // Send TERMINATE packet 
	  /* Complete this part */
	  
	  printf("Download Completed Sucessfully!\n");
	  quitFlag = 0;
	}
	else{ //passwd is not correct. Send another PASS_REQ
	  /* Complete this part */
	  packetcou++;
	}
      }
      else{                                // Send a REJECT to client after 3 wrong passwords
	/* Complete this part */
	quitFlag = 0;
      }
      break;
    default:
      quitFlag = 0;
      break;
    }
  }
  return 0;
}

