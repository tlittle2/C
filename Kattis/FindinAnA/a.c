#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

int main(int argc, char *argv[]){
    char* word= argv[1];
    int idx=0;
    for(int i = 0; i < strlen(word); i++){
        if(word[i] == 'a'){
            idx = i;
            break;
        }
        
    }

    for (int i = idx ; i < strlen(word); i++){
        printf("%c", word[i]);
    }

     printf("\n");

     return 0;


}