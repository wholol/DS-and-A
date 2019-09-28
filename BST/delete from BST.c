#include <stdlib.h>
#include <stdio.h>


struct node{        
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* insert(int data, struct node* root){           //node insertion
   
    if (root == NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        root = newnode;
        root->data = data;
        root->left = NULL;
        root->right = NULL;

    }

    if (data > root->data){
        root->right = insert(data,root->right);
    }

    else if (data < root->data){
        root->left = insert(data,root->left);
    }
    return root;
}

void traverse(struct node* root){       //traverse the node (inorder traversal) 
    
    if (root == NULL){
        return;
    }

    traverse(root->left);
    printf("%d",root->data);
    traverse(root->right);
}

struct node* inOrderSucc(struct node* root){        //find succesor (left msot value of right sub)
    while (root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}


struct node* deletenode(struct node* root,int data){            //this function deletes the node

    if (root == NULL){                  //if no cases
        return root;
    }

    if (root->data == data){

        if (root->left == NULL && root->right == NULL){     //no children
            free(root);  
            root = NULL;                                 //free the root
        }

        if (root->left == NULL && root->right != NULL){ //one child
            struct node* temp = root;                   //let temp point to the node to be deleted
            root = root->right;                         //update the pointer of root to the right child pointer
            free(temp);
            temp = NULL;
        }

        if (root->right == NULL && root->left != NULL){ // one child
            struct node* temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }

        if (root->right != NULL && root->left != NULL){ //two children
            struct node* temp = inOrderSucc(root->right);  //find the inorder succesor of root.
            root->data = temp->data;    //copy that value to the root to be "deleted"
            root->right = deletenode(root->right,temp->data);     //find the inorder succesor's node and delete it. 
        }

    }

    if (data > root->data){
        root->right = deletenode(root->right,data);
    }

    if (data < root->data){
        root->left = deletenode(root->left,data);
    }
    return root;
}


int main(){
   
    root = insert(1,root);
    root = insert(2,root);
    root = insert(3,root);
    root = insert(4,root);
    root = insert(5,root);
    root = deletenode(root,3);
    traverse(root);
}