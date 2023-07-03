#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
} Queue;


void init_queue(Queue* q){
   q->head = NULL;
   q->tail = NULL; 
}

bool enqueue(Queue* q, int v){
    //create  new node
    Node* newNode = malloc(sizeof(Node));

    //if we fail to malloc the new node, ABORT MISSION
    if(newNode == NULL){
        return false;
    }

    //initialize properties of the node
    newNode->value = v;
    newNode->next = NULL;


    //if there is a tail, connect the new node to the tail and make the new node the new tail
    if(q->tail !=NULL){
        q->tail->next = newNode;
    }

    q->tail = newNode;

    //If there is nothing inside of the queue, make the new node the head of the list
        //make sure the head still makes sense
    if(q->head == NULL){
        q->head = newNode;
    }

    return true;

}

int dequeue(Queue* q){
    //if the queue has no values, don't try to dequeue
    if(q->head == NULL){
        return -1;
    }

    //make a variable that will point to the old head because we will have to free its memory
    Node* temp = q->head;
    
    //store the value of the old head so that we can see what got dequeued
    int result = temp->value;

    //the new head is going to be the node immediately after the old head
    q->head = q->head->next;

    //if the head becomes null afterwards, that means there is nothing left in the queue and we need to set the tail accordingly
    if(q->head == NULL){
        q->tail = NULL;
    }

    //free the temporary node from memory to prevent memory leaks and return what we dequeued
    free(temp);
    return result;
    
}


int main(){
    Queue * qu;
    init_queue(qu);
    //printf("Attempting to enqueue value %d\n", enqueue(qu, 1));
    //printf("Popping from the stack. Value we are popping is %d\n", dequeue(qu));

    return 0;
}