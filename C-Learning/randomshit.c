#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "DLL.h"


int get_sum(listelem *list, listelem *a)
{
    if(dll_is_last(a))
        return dll_get_value(a);
    else
        return dll_get_value(a) + get_sum(list, dll_next(a));
}


int main(int argc, char* argv[])
{
    int numbers;
    int totalsum;
    listelem *a = NULL;
    int random;
    listelem *list = dll_create();
    srand(time(NULL));
    
    printf("Enter amount of numbers to generate:\n");
    scanf("%d", &numbers);

    for (int i=0; i<numbers;i++)
    {   
        random = rand() % 10;
        dll_add(list, a, random, DLL_AFTER);
    }

    if(numbers < 10)
        dll_out_list(list);
    else
    {
        for(int c=0;c<numbers; c++)
        {
            printf("%d\n", dll_get_value(a));
            a = dll_next(a);
        }
    }
    
    printf("\n");

    a = dll_get_first_pos(list);
    totalsum = get_sum(list, a);
    
    printf("Total sum = %d\n", totalsum);

    return 1;
}

