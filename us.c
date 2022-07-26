#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include <fcntl.h>

#define REMOTEPORT 1234

int main(int argc,char *argv[])
{
  
//if(argc!=4)
//{
//	printf("Invalid Arguments\n");
//	exit(0);
//}
  int limit=atoi(argv[3]);  
  int sockfd,counter=0,i=0,n,r;
  char buffer[64001],ch;
  struct sockaddr_in   receiverAddr;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  short PORTNO=(short)atoi(argv[1]);
  memset(&receiverAddr, 0, sizeof(receiverAddr));
  bzero(&receiverAddr,sizeof(receiverAddr));
  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_port = htons(PORTNO);
  receiverAddr.sin_addr.s_addr = INADDR_ANY;  //We dont want to bind the socket to specific address//
  sendto(sockfd, argv[2] , strlen(argv[2]), 0, (struct sockaddr *)&receiverAddr, sizeof(struct sockaddr));
  sendto(sockfd, &limit , sizeof(limit), 0, (struct sockaddr *)&receiverAddr, sizeof(struct sockaddr));
  FILE *fp;
  fp=fopen(argv[2],"r");
  fseek(fp,0,SEEK_END);
  size_t filesize=ftell(fp);
  //printf("%ld\n",filesize);
  fseek(fp,0,SEEK_SET);
  n=filesize/limit;
  n++;  
  while(i!=n)
  {     
	if(counter==limit)
	{
	   counter=0;
           i++;	   
  	if((sendto(sockfd,buffer,limit, 0, (struct sockaddr *)&receiverAddr, sizeof(struct sockaddr)))<0)
  	{
//		printf("File not sent\n");
  	}

	}
        buffer[counter]=fgetc(fp);
        counter++;	
  }
  sendto(sockfd,buffer,0, 0, (struct sockaddr *)&receiverAddr, sizeof(struct sockaddr));
  fclose(fp);
  close(sockfd);
  return 0;
}

