#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 25

int myStack[STACK_SIZE];
int top = -1;

bool push(int val){
    //check if stack we are going beyond limits of stack
    if(top >= STACK_SIZE-1){
        return false;
    }

    //allocate to the top and add the value
    top++;
    myStack[top] = val;

}

int pop(){
    //check if there is anything in the stack to pop from
    if(top == -1){
        return -1;
    }

    //deallocate from stack and return the new value at the new top
    top--;
    return myStack[top];

}

int main(){
    printf("Adding: %d\n", push(1));
    printf("Adding: %d\n", push(2));
    printf("Adding: %d\n", push(3));
    printf("Adding: %d\n", push(4));

    printf("Performed pop. New top is now: %d\n", pop());
    

}