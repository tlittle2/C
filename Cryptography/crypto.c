#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char* message;

    scanf("%s", message);

    printf("%li", sizeof(message)-1);


    return 0;
}