#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include <limits.h>



unsigned long long int fib(int n) {
/* SEQUENCE NUMBERS: 0,1,1,2,3,5,8,13,21,24,... */

	unsigned long long int lower = 0;
	unsigned long long int middle = 1;
	unsigned long long int next = 1;
	int i;

	if(n == 0){
		return 0;
	}

	if(n == 1){
		return 1;
	}

	else{
		printf("Fibonacci series: %d,%d,", lower, middle);
		for(i=0; i<=(n-2); i++){
			printf("%llu,", next);
			lower = middle;
			middle = next;
			next = lower + middle;
		}
			}

	return next;
}


int is_consonant(char c){
	char *consonants = "bcdfghjklmnpqrstvwxyz";
	for(int i=0; i<strlen(consonants); i++){
		if(c == consonants[i]){
			return 1;
		}
	}
	return 0;
}


char *rovarsprak(char *start){
	char *reworked = malloc(3 * sizeof(start));
	//char reworked[(strlen(start) * strlen(start))];
	char *o = "o";
	int i, i2, i3 = 0;

	for(i=0; i<strlen(start); i++){
		if(is_consonant(start[i])){
			strncat(reworked, &start[i], 1);
			strncat(reworked, &o[0], 1);
			strncat(reworked, &start[i], 1);
		}
		else{
			strncat(reworked, &start[i], 1);
		}
	}
	return reworked;
}


char *karpsravor(char *start){
	char *reworked = malloc(3 * sizeof(start));
	char *o = "o";
	int i;
	for(i=0; i<strlen(start); i++){
		if(is_consonant(start[i])){ 
			strncat(reworked, &start[i], 1);
			i += 2;
		}
		else{
			strncat(reworked, &start[i], 1);
		}
	}
	return reworked;
}



int main(/*int argc, char* argv[]*/) {

	int upper = 11000;
	clock_t t, t2, t3; 
	int i;
	char b[2] = "b";
	char to_rovar[100];
	//char *to_rovar = "progp";
    t = clock(); 
	unsigned long long int f = fib(upper);
	t = clock() - t;
	printf("\nFibbonaci sequence of %d is: %llu \n",upper, f);
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("fib(%d) took %f seconds to execute \n",upper, time_taken); 
	

	t2 = clock();
	char *normal_str = "progp";
	
	char *rovar_str = rovarsprak(normal_str); // converts normal_string to rovasrsprak
	t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds 
	printf("Converted an array of %lu to rovarsprak in %f seconds\n", strlen(normal_str), time_taken2);
	printf("The new arracy became %d characters long\n", strlen(rovar_str));

	char *btn = karpsravor(rovar_str); // btn = back to normal
	t3 = clock();
	double time_taken3 = ((double)t3)/CLOCKS_PER_SEC; // in seconds 
	printf("Reverted back to normal language in %f seconds\n", time_taken3);

	

	return 1;
}
