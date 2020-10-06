#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(void){


	char* ptr1 = NULL; 

	ptr1 = malloc(4* sizeof(char));

	printf("%p\n",ptr1);

	free(ptr1);

	char* ptr2 = NULL; 

	ptr2 = malloc(4* sizeof(char));

	printf("%p\n",ptr2);

	free(ptr2);

	return 0;
}

