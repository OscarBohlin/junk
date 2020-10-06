#include <stdio.h>
#include <time.h>

unsigned long long int fib(unsigned int n){
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	else if(n > 1){
		int start = 0;
		int middle = 1;
		int result = start + middle;

		for(int i = 1; i <= n; i++){
			start = middle;
			middle = result;
			result = middle + start;
		}
		return result;
	}
	return 0;
}


int main(void){
	unsigned int n;
	unsigned long long int a;
	clock_t start;
	clock_t end;
	double time_spent;

	printf("Ange ett godtyckligt heltal: ");
	scanf("%u",&n);

	start = clock();
	a = fib(n);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Fib(%u) = %llu\n",n,a);
	printf("The operation took %lf seconds\n",time_spent);

	return 0;
}
