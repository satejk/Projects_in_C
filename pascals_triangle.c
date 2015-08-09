#include<stdio.h>


#define MaxRow 10


int main(){



	int leadingspaces = 2 * MaxRow;

	int RowNo;
	int n, s;


	int Row[MaxRow];



	// Set the first element of array Row to 1 and others to zero
	Row[0] = 1;

	for (n = 1; n < MaxRow ; n++){

		Row[n] = 0;


	}




	for(RowNo = 1 ; /*break will terminate the loop*/; ++RowNo){

		//print the leading spaces

		for (s = 1 ;s < leadingspaces ;s++){

			printf(" ");


		}

		//print the numbers on one line
		for (n = 0; n < RowNo ; n++){

			printf(" %4d ",Row[n]); //%4d means 4 chars wide

		}

		printf("\n"); //new line


		leadingspaces -= 2; 

		//terminate the loop if last row is reached

		if(RowNo == MaxRow){

			break;

		}


		//calculate the next row


		for(n = RowNo ; n >= 1; --n){


			Row[n] += Row[n-1];


		}


	}














	return 0;


}