#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#define BUFSIZE 128

int main(void){


	char command[BUFSIZE];

	int status;

	pid_t pid;


	for(;;){

		printf("simplesh: ");
		if (fgets(command,sizeof(command),stdin) == NULL)
		{
			printf(" null \n");

			return 0;
		}

		command[strlen(command) - 1] = '\0';
		if((pid = fork()) == 0){

			execlp(command,command,0);



		}

		while(wait(&status) !=pid){

				continue;

		}

		printf("invalid command \n");
	}



}