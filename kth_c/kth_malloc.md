
 * Malloc inkluderas via stdlib.h
 *
 * 
 *
 *

NULL går ej att ändra på, kompileras ej.




Ingen jävla aning.



*/

# Att besvara:

## 1
#### a. I vilken header-fil finns `malloc`?
```
Malloc inkluderas via stdlib.h
```
#### b. Beskriv skillnaden mellan `malloc`, `calloc`, och `free`.
```
Malloc allokerar minne av en viss storlek, free frigör minne, calloc nollställer minnet den skapar men fungerar annars som malloc
```

#### c. Vad är `NULL`? Googla gärna hur `NULL` är definierad i `stddef.h`. 
```c
NULL är värdet av en null pekar, definierad som void* 0. används för error handling och initialisering av oinitierade men dekllarerade minnes pekare. 

NULL = void* 0
```

#### d. Vad händer om man dereferencar en NULL pointer?

```c
kan göras via 
#define NULL
men inte annars.

```

## 2
#### a. Nämn minst två skillnader mellan stack och heap.
```
stack innehåller en stack pekare som berätar vart programmet skall fortsätta exikvera kod efter att en funktion är klar, Stack kan inte minska i storlek, vilket heap kan.
```

#### b. (I språket C) Hur vet du om du allokerat minne på stacken eller heapen?

```
Lokala variablar till funktioner sparas till stacken medans globala varablar sparas i heap.
```

## 3
#### a. Vad är `memory leak`? Vad skapar det för problem, och hur undviker man det?
```
Memory leak är är icke använd allokerat minne inte frigörs, utan programmet håller kvar vid sitt allokerade minne. Detta kan unvdikas via free()
```

#### b. Vad är `buffer overflow`? Vad skapar det för problem, och hur undviker man det?

```
En buffer overflow är när information i tex en sträng överskrider dess stack pekare, vilket kan leda till arbitrary code execution. Se till att hålla koll på hur mycket du kopierar/skriver när du skriver till en buffer

```

#### c. Vad finns det för risker involverade med funktionen `free`, dvs om man använder den fel?

```
idk
```

## 4
#### a.
När man pratar om `security bugs` eller `vulnerabilities` brukar man mena buggar i programmet som kan utnyttjas till att t.ex. krasha ett program, stjäla/ändra information, eller till och med injicera sin egen kod. De kan alltså leda till mycket stora problem, och är av högsta prioritet att fixa.
 
Hur stor procentuell andel av security bugs är memory safety issues i **Chrome, Windows, och macOS** respektive? Jag sa inte helt rätt på övningen, så googla! Skriv ned, utöver svaren, källorna där ni hittade svaren.

```
* Windows: 70%  (https://www.zdnet.com/article/microsoft-70-percent-of-all-security-bugs-are-memory-safety-issues/)

* Chrom: 70% (https://www.zdnet.com/article/chrome-70-of-all-security-bugs-are-memory-safety-issues/)

* macOS: idk
```


#### b.
Kan man helt undvika memory safety issues? Isåfall hur?
```
jag tror det, genom att på ett korrekt sätt hantera minne, allokering, free samt bufferskrivning så att inga bufer overflows sker. 
```

# Att koda:

## refree.c
1. Allokera med `malloc` minne som kan hålla 4x `char`. Pekaren `ptr1` ska sparas som typen `char*`.
2. Skriv ut minnesaddressen med `%p`.
3. Frigör minnet.
4. Upprepa steg 1-3 med ny pekarvariabel `ptr2`.

Vad blir de båda minnesaddresserna? Varför?
```c
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
```
```
Minnes addresserna blir densamma, jag vet inte varför
```

## deterministic.c
1. Initialisera slumpnummergeneratorn med hjälp av `srand` och seeden `0`.
2. Skapa en funktion med signaturen `void randomize_memory(void* ptr, size_t size)` som använder pekararitmetik och `rand` för att randomisera minnet av storleken `size` vid addressen `ptr`, en byte (`char`) i taget.
3. Skapa en funktion med signaturen `int loopy(uint16_t target)` som allokerar minne för en `uint16_t`, och randomiserar det med hjälp av din `randomize_memory`. Frigör minnet innan du returnerar värdet `0`.
4. Ändra din `loopy` så att den loopar för evigt, och i varje loop allokerar minne, slumpar det, testar om det blev lika med `target`, och isåfall returnerar antalet försök det tog att hitta. Nytt minne ska allokeras i varje iteration. Minnesläckor är ej tillåtna.
5. Seeda om srand med värden mellan 0 och 1000, och hitta de värden som ger lägst och högst antal attempts för anropet `loopy(12345)`. Printa också dessa med hjälp av `printf("Min: %d:%d\nMax: %d:%d\n", minIndex, minAttempts, maxIndex, maxAttempts);`

Trots att `srand` med konstant random seed alltid kommer att ge samma slumpnummer, så kan du fortfarande få olika output med olika platformar och kompilatorer. Känner du dig nöjd med din kod, testa den då på https://repl.it/languages/c - du bör dock utveckla och testa koden lokalt.
Har du gjort rätt så ska output bli:

## hask.c

En länkad lista är antligen en tom lista, eller ett värde och en pekare. Pekaren kan vara NULL, vilket indikerar slutet på listan, eller så kan den peka på nästa element i listan. [En bild finns här.](https://miro.medium.com/max/3076/0*XqSjmmifDADTpaDk) För att göra det lite lättare för oss, så ska vi inte hantera specialfallet då listan är tom, och element kan bara vara integers.

I `src/hask.h` finns en headerfil som ni ska använda. Den innehåller en struct (som ej behöver ändras), och några funktioner som ni ska implementera i `hask.c`. Vad funktionerna ska göra står i kommentarer i header-filen.

Var noga med att frigöra minne när ni tar bort element i er `Hask`.

#### Frivillig extrauppgift: Hantera specialfallet då den länkade listan är tom.