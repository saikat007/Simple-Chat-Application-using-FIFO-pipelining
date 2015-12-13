#include <stdio.h> 
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *file1;
	int fifo_server,fifo_client;
	char str[256];
	char *buf;
	char *choice;
	printf("Welcome to a simple chat application\n\n");
	if(fork() == 0){   
		while(1){
			 choice = malloc(10*sizeof(char));
			 scanf("%s",choice);
			 fifo_server=open("fifo_server",O_RDWR);
			 write(fifo_server,choice,sizeof(choice));
		}    
	}
	else{
		while(1){
			fifo_client = open("fifo_client",O_RDWR);
			read(fifo_client,choice,sizeof(choice));
			printf("%s\n",choice);
		}
	}
	close(fifo_server); 
	close(fifo_client);  
}
