#include <stdio.h>


int main(){

	static char who[50];
	
	int size = 10;


	

	char *ptr;


	//char *str = (*char)malloc(sizeof(char)*size);

	printf("enter a string: \n");
	scanf("%s",who);

	

	ptr = who + (sizeof(who)/sizeof(char));

	while(--ptr >= who){

		putchar(*ptr);



		
	}
		printf("\n");

	//printf("%ld\t%ld\n",sizeof(who),sizeof(char));
	

	return 0;
}
