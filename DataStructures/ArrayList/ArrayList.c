#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//This is more of a dynamic array than an arraylist

int* arr;
size_t arrSize = 256;

int main(){
    //calloc 2 parameters- count of the arraysize, and the size of each input in the array 
        //(in this case it's int, so we allocate for ints)- DOES IT MULTIPLY THESE 2 VALUES TOGETHER TO GIVE THE CORRECT OUT OF MEMORY
    arr = calloc(arrSize, sizeof(int));

    arr[14] = 21;
    printf("%d\n", arr[14]);

    arrSize = 512;
    //realloc has 2 parameter- the address block of the thing we are reallocating for, and the new size of the thing we are allocating for
    arr= realloc(arr, arrSize * sizeof(int));
    printf("%d\n", arr[14]);

    free(arr);
}