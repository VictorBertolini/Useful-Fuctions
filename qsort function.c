#include <stdio.h>
#include <stdlib.h>

/**
 * qsort FUNCTION
*/

int compareCrescent(const void *x_void, const void *y_void)
{
    int x = *((int *) x_void);
    int y = *((int *) y_void);

    return y - x; //Pay attention here
}

int compareDecreasing(const void *x_void, const void *y_void)
{
    int x = *((int *) x_void);
    int y = *((int *) y_void);

    return x - y; //And here
}

int compareChar(const void *x_void, const void *y_void)
{
    char x = *((char *) x_void);
    char y = *((char *) y_void);

    return x - y; //The letter with lower number in ascii will be first (A, B, C...)
}

void showArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("[ %d ] ", *(array + i));
    
    printf("\n");
}


int 
main()
{
    int array[10] = {5, 7, 4, 8, 1, 9, 3, 0, 2, 6};
    int length = 10;

    printf("The original array:\n");
    showArray(array, length);

    printf("The array in crescent order:\n");
    qsort(array, length, sizeof(int), compareCrescent);
    showArray(array, length);
    
    printf("The array in decrescent order:\n");
    qsort(array, length, sizeof(int), compareDecreasing);
    showArray(array, length);


    char arrayNames[6][10] = { "Victor", "Jose", "Anna", "Kelson", "Zi", "Abrao"};
    int num = 6;

    printf("The names organized by alphabetic order (Just firts letter):\n");
    qsort(arrayNames, num, sizeof(char) * 10, compareChar);

    for (int count = 0; count < num; count++)
        printf("[ %s ] ", arrayNames[count]);
    
    return 0;
}