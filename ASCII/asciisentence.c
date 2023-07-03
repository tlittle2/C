#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){
    char* s = argv[1];
    
    printf("%s\n", s);
    

    for(int i = 0; i < strlen(s); i++){
        printf("%c : %i ----> %p\n", s[i], s[i], s[i]);
        
    }

    return 0;


}