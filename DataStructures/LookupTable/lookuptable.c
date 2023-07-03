#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* messages[10] = {};


int numofMessages = (sizeof(messages) / sizeof(char *));


void updateTable(int x, int y, char* s){
    while(x < y){
        messages[x] = s;
        x++;
    }

}

void printInfo(int idx){
    if(idx > numofMessages -1){
        printf("Exceeded the length\n");
    }else{
        printf("%s\n", messages[idx]);
    }

}


int main(){
    updateTable(0, 3, "this is the beginning of the list");
    printInfo(2);


    for(int i = 0; i < numofMessages; i++){
        printf("%i: %s\n", i, messages[i]);
    
    }

    printf("------------------\n");

    updateTable(3, 7, "this is the middle of the list");

    for(int i = 0; i < numofMessages; i++){
        printf("%i: %s\n", i, messages[i]);
    }





}