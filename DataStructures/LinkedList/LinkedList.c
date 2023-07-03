#include <stdlib.h>     //needed for dealing with nulls
#include <stdio.h>      //needed for printf()
#include <stdbool.h>    //needed for boolean values

typedef struct Node{
    int data;
    struct Node* next;

}Node;



void printList(Node* head){
    //set a temporary node to be the head, so that we can move the temporary pointer to each node and access the data in each node
    Node* temp = head;
    
    while(temp!= NULL){
        printf("%d ---", temp->data);
        temp= temp->next;

    }
    printf("NULL");
    printf("\n");
}

Node* addToFront(int val){
    //allocate memory for new node, set value and its pointer to null
    Node *newNode = malloc(sizeof(Node));
    newNode->data= val;
    newNode->next= NULL;
    return newNode;

}

void addToBack(Node **head, int val){
 //we need the double pointer **head because if the front is null, we need to change the address that the root pointer points to
    Node *newNode = malloc(sizeof(Node));;
    newNode -> data = val;
    newNode -> next = NULL; 
    

    //if the value of the head is null, then we have an empty list and we need to change the address of the head 
    if(*head == NULL){
        *head = newNode;
    }else{
        Node *curr = *head;
        while(curr-> next != NULL){
            curr= curr->next;
        }
        curr->next = newNode;
    }    
}

void deletePosition(Node** head, int p){
    //We need double pointer because we are manipulating the list

    //if the list is empty, return NULL
    if(*head == NULL){
        return;
    }

    //make a temporary pointer node that points to the head (this will be what walks the list)
    Node* temp = *head;

    //if position we desire to remove is the head, then the head will now be temp.next because temp and head are initially the same
    //we also must free temp. Temp is currently the head, meaning we must remove it from memory (no garbage collection in C)
    if(p == 0){
        *head = temp->next;
        free(temp);
        return;
    }
    
    //we must subtract one after this to get to the next value
    //if the parameter is = 1, we must do p-1 first in order to get index 1. if p==0 after this initial subtraction, then we skip the 
        //while loop
    p-=1;

    //walk the list if we p is still not equal to 0, subtracting from p along the way
    while(p!=0){
        temp = temp->next;
        p-=1;
        
    }

    //set a variable equal to the node following the one we wish to delete
    Node* newNext = temp->next->next;
    
    //go to node before the one we wish to delete (this is temp). Delete it's next node, and temp's next node will become the newNext 
    free(temp->next);
    temp->next = newNext;

}

int main(){

    
    Node* head1;
    Node* temp1;

    //allocate to front --- should look like 21, 420, 69
    temp1= addToFront(69);
    head1 = temp1;
    
    temp1 = addToFront(420);
    temp1->next = head1;
    head1 = temp1;


    temp1= addToFront(21);
    temp1->next = head1;
    head1= temp1;

    printf("FRONT METHOD\n");
    printList(head1);
    
    printf("AFTER DELETE at position 0\n");
    deletePosition(&head1, 0);
    printList(head1);

    printf("\n");

    //------------------------------------------

    Node* head2 = NULL;
    Node* temp2;

    addToBack(&head2, 42);
    addToBack(&head2, 21);
    addToBack(&head2, 72);

    printf("BACK METHOD\n");    //expect 42, 21, 72
    printList(head2);
  

}