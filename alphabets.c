//Author: SATEJ VINAYAK KHANDEPARKAR
// MASTERS IN EMBEDDED AND INTELLIGENT SYSTEMS
// HALMSTAD UNIVERSITY , SWEDEN. 

//This code checks every alphabet entered if it either uppercase
// lower case, digit or a special symbol.

#include<stdio.h>


int main()
{
	char letter;
	int i = 0;
	
	
	
	//start checking 
	while (1)
	{
	
	printf("Enter a letter: \n");
	scanf("%c",&letter);
	
	if( letter >= 65 && letter <= 90)
		{
			//checking for capital letter
			printf(" %c is Capital letter \n ", letter);
		
		}

	else if (letter >= 97 && letter <=122)
		{
			//checking for small case letter
			printf(" %c is small case letter \n",letter);
			
		}
	else if (letter >= 48 && letter <= 57)
		{
			//checking for digits
			printf(" %c is a digit \n",letter);
		
		}
		
	else if ((letter >= 0 && letter <=47)||(  letter >= 58  && letter >= 64 )||( letter >= 91 &&  letter >= 96)||( letter >= 123 && letter >= 127 ))
		{
			//checking for special symbols
			printf(" %c is a special symbol \n",letter);
		
		}	
	else 
		{
			//error message
			printf("INVALID CHARACTER \n");
		
		}	
		
		
	printf("**********************************************************\n");	
	
	
	}
	return 0;

}
