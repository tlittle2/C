#include <stdlib.h>
#include <stdio.h>

//Types of comparator functions
     //<0  The element pointed by p1 goes before the element pointed by p2
    // 0   The element pointed by p1 is equivalent to the element pointed by p2 -> returns original list?
   // >0   The element pointed by p1 goes after the element pointed by p2
//In this case we want the <0 case because we want to sort in ascending order

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a == *(int*)b );
}


int main(){
    int arr[26];

    for(int i = 0; i < 26; i++){
        arr[i] = (26 -i) * 2; 
    }
    
    printf("Unsorted List: ");
    for(int i = 0; i < 26; i++){
        printf("%d, ", arr[i]);
    }

    printf("\n");
    qsort(&arr, 26, sizeof(int), cmpfunc);
//Params: addr of array, size of array, size of the data being stored(int, float, double, etc), comparator function
    printf("  Sorted List: ");
    for(int i = 0; i < 26; i++){
        printf("%d, ", arr[i]);
    }

    printf("\n");
    return 0;
}