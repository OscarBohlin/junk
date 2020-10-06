/*
 *
 * Malloc inkluderas via stdlib.h
 *
 * Malloc allokerar minne av en viss storlek, free frigör minne, calloc nollställer minnet den skapar men fungerar annars som malloc
 *
 *NULL är värdet av en null pekar, definierad som void* 0. används för error handling och initialisering av oinitierade men dekllarerade minnes pekare.

NULL går ej att ändra på, kompileras ej.


stack innehåller en stack pekare som berätar vart programmet skall fortsätta exikvera kod efter att en funktion är klar, Stack kan inte minska i storlek, vilket heap kan.

Ingen jävla aning.



*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define NULL 1
int main(void){

	printf("%d\n",NULL);

	printf("Setting NULL to 1\n");
	printf("%d\n",NULL);
	return 0;
}
