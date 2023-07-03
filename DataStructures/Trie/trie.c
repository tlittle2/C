#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define CHAR_SIZE 256

typedef struct Node{
    char value;
    bool isLeaf; //value is 1 if node is a leaf
    struct Node* children[CHAR_SIZE]; //define an arrays that can store any of the 26 letters in the alphabet

} Node;


Node* createNode(){
    Node* result = malloc(sizeof(Node));

    for (int i = 0; i < CHAR_SIZE; i++){
        result->children[i] = NULL;
    }
    result->isLeaf = false;
    
    return result;

}

bool insert(Node** root, char* val){
    printf("Inside add function\n");    

    //set value of the node
    if(*root == NULL){
        (*root)= createNode(val);

    }

    Node* temp = *root;
    int length = strlen(val);

    for(int i = 0; i < length; i++){
        if(temp->children[val[i]] == NULL){
            temp->children[val[i]] = createNode();
        }
        temp = temp->children[val[i]];
    }

    if (temp->isLeaf){
        return false;
    } else{
        temp->isLeaf = true;
        return true;
    }

}


static void printTrieRecursive(Node* currNode, char* prefix, int length){
    printf("CURR: %p, %s \n", currNode->children, prefix);
    char newPrefix[length+2];
    memcpy(newPrefix, prefix, length);

    newPrefix[length+1] = 0;

    if(currNode->isLeaf){
        printf("OUR NEW WORD IS: %s\n", prefix);
    }

    for(int i = 0; i < CHAR_SIZE; i++){
        if(currNode->children[i] != NULL){
            newPrefix[length] = i;
            printTrieRecursive(currNode->children[i], newPrefix, length+1);
        }
    }
    
}

void printTrie(Node* root){
    if(root == NULL){
        printf("OUR TRIE IS EMPTY!\n");
        return;
    }

    printTrieRecursive(root, NULL, 0);


}

int main(){
    Node* root = NULL;

    insert(&root, "trevor");
    insert(&root, "trey");

    insert(&root, "trebeke");

    printTrie(root);
    



    return 0;
}