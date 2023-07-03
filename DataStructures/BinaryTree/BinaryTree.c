#include <stdlib.h>     //needed for dealing with nulls
#include <stdio.h>      //needed for printf()
#include <stdbool.h>    //needed for boolean values

//this tree allows the same number multiple times

typedef struct treeNode{
    int value;
    struct treeNode *right; //point to the right child
    struct treeNode *left; //point to the left child
} treeNode;


treeNode *createNode(int v){
    //allocate new node onto heap
    treeNode* result = malloc(sizeof(treeNode));

    //set thte node where it needs to be
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = v;
    }

    //return the result
    return result;

}

void insertnumber(treeNode **rootptr, int val){
//we need the double pointer **rootptr because if the tree root is null, we need to change the address that the root pointer points to

    //root is a temporary pointer that points to wherever the root pointer is pointing to
    
    treeNode* root = *rootptr;
    if (root == NULL) {
        (*rootptr)= createNode(val);
        return;

        //if the root is null, we will create a new root/node and have the root pointer point to this new node
    }

    if (val < root->value) {
        return insertnumber(&(root->left), val);
    } else {
        return insertnumber(&(root->right), val);
    }

}

bool findNumber(treeNode* root, int val){
    //no double pointer in parameters because we are not changing the tree at all, we are simply searching through the tree

    if(root == NULL){
        return false;
        //return false if tree is empty
    }

    //this will just return the first found value that is equal to val
    if(root->value == val){
        return true;
    }

    
    if(val < root->value){
        return findNumber(root->left, val);
    }else{
        return findNumber(root->right, val);
    }
}

treeNode *helpGetMax(treeNode *root){
    while(root->right != NULL){
        root = root ->right;
    }

    return root;

}

treeNode *getMax(treeNode *root){
    treeNode *max;
    if(root->right != NULL){
        max = helpGetMax(root->right);   
    }
    return max;
}


treeNode *helpGetMin(treeNode *root){
    while(root->left != NULL){
        root = root ->left;
    }

    return root;

}

treeNode *getMin(treeNode *root){
    treeNode *min;
    if(root->left != NULL){
        min = helpGetMin(root->left);   
    }
    return min;
}

void inOrder(treeNode *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}

int main(){
    treeNode *root = NULL;

    insertnumber(&root, 15);
    insertnumber(&root, 7);
    insertnumber(&root, 4);
    insertnumber(&root, 20); 
    insertnumber(&root, 69);

    inOrder(root);
    printf("\n");

    int numtoFind= 100;
    
    if(findNumber(root, numtoFind) == 1){
        printf("Your value has been found: %d", numtoFind);
    }else{
        printf("%d IS NOT IN THE TREE ", numtoFind);
    }
    
    printf("\n");


    printf("%d\n", getMax(root)->value);


    printf("%d\n", getMin(root)->value);
    
    


}

    