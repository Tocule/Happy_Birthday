#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define BUFFERSIZE 0x8000
	
int main(int argc,char *argv[])
{ 
  FILE *fp;
  char PORTNO[6]; 
  int max_limit;
  char sender_filename[30];
  char receiver_filename[30]="Received_File";
  int choice;
    if(argc==2 || argc==3)
    {   
	do
	{	
	     printf("***Menu***\n");
	     printf("1.Receive Message\n");
	     printf("2.Send Audio,Video,Image File\n");
	     printf("3.Exit\n");
	     choice=(int)atoi(argv[1]);
	     switch(choice)
	     {
		     case 1 : 
			      printf("Enter the port no\n");
		 	      scanf("%s",PORTNO);
			      //system("mkdir Received_Files");
			      //system("gcc ur.c -o ur");
			      //system("cd Receiver");
			      execlp("./ur","./ur",PORTNO,NULL);
			      printf("Do you want to Exit Press 3\n");
			      scanf("%d",&choice);
			      break;
			      


		     case 2:
			      max_limit=atoi(argv[2]);
			      printf("Enter the port no\n");
			      scanf("%s",PORTNO);
			      printf("Enter the filename.format u want to send to your friend\n");
 			      scanf("%s",sender_filename);
			      fp=fopen(sender_filename,"r+");
			      if(fp==NULL)
			      {
			          printf("Failed_to_open_file");
		                  exit(0);
		              }
	    		      fseek(fp,0,SEEK_END);
			      size_t max_file_read=ftell(fp);
			      fseek(fp,0,SEEK_SET);
			      //printf("%ld",ftell(fp));
	                      if(max_limit>max_file_read || max_limit>64000)
		 	      {
				   argv[2]="64000";
			      //   printf("%s\n",argv[2]);
			      }
			      fclose(fp);
			      printf("File Sent\n");
			      execlp("./us","./us",PORTNO,sender_filename,argv[2],NULL);
			      break;

		     case 3 : printf("You have Exited\n");
			      break;
			   
		     default : printf("Invalid Option\n");
			       exit(0);	      
	    }

 	}while(choice!=3);
    
    }
    else
    {
	printf("Invalid numer of Arguments\n");
	printf("Menu for your reference\n");
	printf("***Menu***\n");
        printf("1.Receive Message | Syntax : ./up 1 \n");
        printf("2.Send Message    | Syntax : ./up 2 (Size limit[Bytes]))\n" );
        printf("3.Exit            | Syntax : ./up 3\n");
     }
  
  return 0;
 } 

