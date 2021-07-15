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
    // Variable to contain the received data (easily handle on the heap)
    char *datamsg = (char *) malloc(sizeof datamsg);
    strcpy(datamsg, "");
    
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
    char *server_addr;

    // Instance of the union packet and while-flag
    Packets packet;
    int quitFlag = 1;

    // Need for the sendto and recvfrom
    struct sockaddr_storage their_addr;
    socklen_t addr_len = sizeof their_addr;

    //Passwords for login
    char *passwd1, *passwd2, *passwd3;

    //File to download
    char *fileOut;

    if(argc != 7){
      printf("Not enough or too many arguments!\n");
      exit(1);
    }

    server_addr = argv[1];
    server_port = argv[2];
    fileOut     = argv[6];

    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    
    if ((rv = getaddrinfo(server_addr, server_port, &hints, &servinfo)) != 0) {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
      printf("ABORT");
      exit(1);
    }

    // loop through all the results and make a socket
    for(p = servinfo; p != NULL; p = p->ai_next) {
      if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
	perror("client: socket");
	continue;
      }
      break;
    }
    
    if (p == NULL) {
      fprintf(stderr, "client: failed to create socket\n");
      printf("ABORT");
      exit(1);
    }
    
    //COMMUNICATE WITH SERVER
    
    // 1 . SENDING JOIN_REQ PACKET
    packet.ctrl_msg.header = htons(1);    //convert unsigned short interger from host byte order to network byte order
 
    /*
      Complete this part (sending JOIN_REQ PACKET)
    */

    // 2. RECEIVED PACKAGES FROM SERVER & PROCESS
   
    while(quitFlag)
    {
      /*Complete this part (receive a packet from the server */
      
      switch(ntohs(packet.ctrl_msg.header)){ // Check the header of the received packet
      case PASS_REQ:                         // Receive PASS_REQ packet from server. Send PASS_RESP_PACKET to
	/* Complete this part */
	break;
      case PASS_ACCEPT:                      // Receive PASS_ACCEPT packet from server. Do nothing
	break;
      case DATA:                             // Receive DATA_PACKET from server. Get the data using strapp() function in helper_function.c. Write data to file (for exp. out.txt)
	/* Complete this part */
	break;
      case TERMINATE:                        // Receive TERMINATE packet from server. Check the SHA1 digest
	// Calculate SHA1-Digest (see Lab2) from the received data 
	/* Complete this part*/
	 
	for(int i = 0; i < sizeof(sha1_hash); i++)        //Convert 20 byte Hex values sha1_hash to string sha1_hash_str
	  sprintf(sha1_hash_str+(i*2), "%02x", sha1_hash[i]);

	//printf("SHA1-Digest: %s", sha1_hash_str);

	//Compare with the received packet.terminate.digest
	if(strcmp(sha1_hash_str, packet.terminate.digest) == 0)
	  printf("DATA INTEGRITY CONFIRMED!\n");
	else
	  printf("DATA HAS BEEN ALTERED!\n");
	printf("Download Completed Succesfully!\n");
	quitFlag = 0;
	break;
      case REJECT:                            // Close the session
	printf("Wrong password 3 times!\n");
	printf("ABORT!\n");
	quitFlag = 0;
	break;
      default:
	quitFlag = 0;
	break;
      }
    }

    // Do some cleaning
    freeaddrinfo(servinfo);
    free(datamsg);
    close(sockfd);

    return 0;
}
