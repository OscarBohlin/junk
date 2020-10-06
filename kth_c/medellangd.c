#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IN 1 /*Inside a word*/
#define OUT 0 /*Outside a word*/

int main(void){

	char c;
	char str[100];
	int nl,nw,nc,state;
	double nc_per_word;
	state = OUT;
	nl =  nw = nc = 0;


	printf("Please enter strig to analyze, end with newline: ");

	while((c = getchar()) != '\n' && nc < sizeof(str)){
		str[nc] = c;
		if(c == '\n'){
			nl++;
		}
		if(c == '\n' || c == '\t' || c == ' ' || c < 65){
			state = OUT;
		}
		else if(state == OUT){
			state = IN;
			nw++;
		}
		nc++;
	}

	nc_per_word = (double)nc/nw;

	printf("Number of words in string: %d\n",nw);
	printf("Number of characters in string: %d\n",nc);
	printf("Avrage number of character per word: %lf\n",nc_per_word);












	return 0;
}
