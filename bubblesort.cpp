#include<stdio.h>

int * bubble_sort(int * A);

int main()
{
	int i,j,k;
	int A[5]= {1,4,2,6,9};
	int * B;
	
	//Bubble sort 
	
	B =bubble_sort(A);
	for (k=0;k<5;k++)
	{
		printf("%d",B[k]);
		
		
	}
	
	return 0;
	
}


int * bubble_sort(int *A)
{
	
	int i,j,temp;
	int flag;
	
	for (i=0;i<5;i++)
	{
		flag = 0;
		
		for(j=0;j<5;j++)
		{
			if(A[i] < A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				
				flag = 1;
				
			}
			
			
		}
		if (flag == 0) break; //improve time complexity
	}
	
	return A;
	
}
