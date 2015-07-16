#include<stdio.h>

int * selection_sort(int * A);

int main()
{
	int i,j,k;
	int A[5]= {1,4,2,6,9};
	int * B;
	
	//selection_sort
	
	B =selection_sort(A);
	for (k=0;k<5;k++)
	{
		printf("%d",B[k]);
		
		
	}
	
	return 0;
	
}


int * selection_sort(int *A)
{
	
	int i,j,temp;
	int flag;
	int min;
	
	for (i=0;i<5;i++)
	{
		//flag = 0;
		min = i;
		for(j=i+1;j<5;j++)
		{
			if(A[j] < A[min])
			{
				min = j;
				
				temp = A[i];
				A[i] = A[min];
				A[min] = temp;
				
				//flag = 1;
				
			}
			
			
		}
		//if (flag == 0) break; //improve time complexity
	}
	
	return A;
	
}
