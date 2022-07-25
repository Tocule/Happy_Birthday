#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define BUFLEN 700000
#define LISTENPORT 1234

int main(int argc,char *argv[])
{
  
//if(argc!=2)
//{
//	printf("Invalid Arguments\n");
//	exit(0);
//}
 
  int sockfd, len,j,i,limit;
  char buffer[BUFLEN];
  struct sockaddr_in receiverAddr, senderAddr;
  char filename[30];
//size_t filesize;
//for(int i=0;i<30;i++)
//{
//    filename[i]='\0';
//}      
  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket system call failed");
    exit(EXIT_FAILURE);
  }

  bzero(&receiverAddr,sizeof(receiverAddr));
  memset(&senderAddr, 0, sizeof(senderAddr));
  short PORTNO=(short)atoi(argv[1]);
  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_addr.s_addr = INADDR_ANY;
  receiverAddr.sin_port = htons(PORTNO);
  //memset(&(receiverAddr.sin_zero),'\0',8);
  if(bind(sockfd, (const struct sockaddr *)&receiverAddr, sizeof(receiverAddr)) < 0)
  {
    perror("bind syscall failed");
    exit(EXIT_FAILURE);
  }
  len = sizeof(senderAddr);
  recvfrom(sockfd,filename,1024,0,(struct sockaddr *)&senderAddr, &len);
  recvfrom(sockfd,&limit,sizeof(limit),0,(struct sockaddr *)&senderAddr, &len);
  for(i=0;filename[i]!='.';i++)
  {}
  for(j=0;argv[1][j]!='\0';j++)
  {}
  for(;filename[i]!='\0';i++)
  {
     argv[1][j]=filename[i];
     j++;
  }
  argv[1][j]='\0';  
//printf("%s ",filename);
  int fp;
  fp=open(argv[1],O_WRONLY|O_CREAT);	  
  while(recvfrom(sockfd, buffer, limit, 0, (struct sockaddr *)&senderAddr, &len))
  {	       
       	write(fp,buffer,limit);
  }	 
  memset(filename, '\0', sizeof(filename));
  close(fp);
  return 0;
 } 
