
//program is coded from  on http://simplestcodings.blogspot.se as reference
// This is intented for educational purpose only



#include <stdio.h>
#include <string.h>



/* This function returns matched param's value in a buffer */


char* get_param_val(char* buffer, char* param_name){

	char* match;
	
	//strstr(haystack , needle)
	//returns the first occurance of needle in a haystack
	match = strstr(buffer, param_name);
	

	//if(match == NULL)
	//	return NULL;

	//printf("get_param_val() \n");	
	return match;

}



void get_cpu_params(){


	FILE* fp;

	char buffer[1024];
	size_t bytes_read;
	float clock_speed;

	int cache_size;

	char model_name[100];


	printf("get_cpu_params() \n");
	/*read entire contents of /proc/cpuinfo into the buffer */

	//open the file
	fp = fopen("/proc/cpuinfo","r");

		
	//read the file
	bytes_read = fread(buffer,1,sizeof(buffer),fp);

	//close the file after reading
	fclose(fp);


	printf("file read over \n");

	/*return a error if read failed or buffer overflow*/


	if (bytes_read == 0 ){
					
		printf("error in byte_read : NULL \n");		
		return;

		}
	else{

		printf("some other reason \n");


	}

	

	printf("bytes read : %zu \n" , bytes_read);
	

	//segmentation fault
	//strcpy(buffer+1025, '0');

	char *a ;

	buffer[bytes_read] = '\0';

	a = buffer;

	while(*a != '\0'){

		if(*a == '\t'){
			printf("\n");
		
		}
		else{
		printf("%c" ,*a);

		}
		++a;

	}

	printf("error check passed \n");
	//terminate the buffer at the end with NULL char
	

	
	sscanf (get_param_val(buffer , "cpu MHz"),"cpu MHz : %f",&clock_speed);

	printf("CPU clock frequency : %f MHz\n",clock_speed);

	
	sscanf (get_param_val(buffer , "cache size"),"cache size : %d",&cache_size);

	printf("CPU cache size: %d KB\n",cache_size);

	
	sscanf (get_param_val(buffer , "model name"),"model name : %s ",model_name);
	
	printf("Model Name : %s \n",model_name);

	
	

	printf("\n");
	
	
	


}


int main() {
	//printf("main() \n");
	get_cpu_params();
	
	return 0;

}
