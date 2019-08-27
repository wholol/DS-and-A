#include <stdlib.h>
#include <stdio.h>

struct node         //node for the BST
{

int data;
struct node* lchild;        //left child ptr
struct node* rchild;        //right child ptr

};

struct node* root = NULL;       //initialzie root node to be null

void insert(int data)     //insertion using a while loop

{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* t = root;                  //initialize t (traverse) to root
    struct node* r = NULL;                 //a pointer that points to the traverse
    if (root == NULL)       //if the root is NULL (.i.e there tree is empty)
    {
        newnode->lchild = NULL;
        newnode->rchild = NULL;
        newnode->data = data;
        root = newnode;     //let the root ponit to the new node (i.e. very first node)
        return;
    }
     

    while (t != NULL)        //if root is not null
    {
        r = t;
        if (data > t->data)            //if the element is bigger than light child
        t = t->rchild;                //traverse to right side, since right side value is bigger

        else if (data < t->data)
        {
            t = t->lchild;
        }
        else
        {
            return;
        }

    }
  
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->data = data;

    //code below links the newly created node with the BST.

    if (newnode->data > r->data)      //if new node's data is larger than the traverse node
    {
        r->rchild = newnode;          //point the traverse's right child to the newly created node
    }

    else
    {
        r->lchild = newnode;
    }
    }
    
void Inorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->lchild);
    printf("%d", root->data);
    Inorder(root->rchild);
}

void Search(int data){          //search function

        struct node* searchnode = (struct node*)malloc(sizeof(struct node));
        searchnode = root;
        while (searchnode != NULL){
            if (data > searchnode->data){
                searchnode = searchnode->rchild;

            }

            else if (data < searchnode->data){
                searchnode = searchnode->lchild;
            }

            if (data == searchnode->data){
                printf("%d", data);
            }
        }
    
    printf("no value");


}


///recursive inert below////

struct node* RecursionInsert(struct node* root, int data){
    struct node* createnode = (struct node*)malloc(sizeof(struct node));
    if (root == NULL){
        root = createnode;
        createnode->data = data;
        createnode->lchild = NULL;
        createnode->rchild = NULL;
        return root;
    }

    if (data > root->data){
        root->rchild = RecursionInsert(root->rchild,data);
    }

    else if (data < root->data){
        root->lchild = RecursionInsert(root->lchild,data);
    }

    return root;
}
  
int main()
{
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    Inorder(root);
    printf("\n");

}


