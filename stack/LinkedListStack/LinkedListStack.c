
#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;


void push(int data){        //push into stack
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void pop(){     //pop stack
    if (head == NULL)
    {
        printf("empty stack");
        return;
    }
    else{
         struct node* deletenode = head;
         deletenode = head;
         head = head->next;
         free(deletenode);
    }
}

void PrintStack(){      //print stack
    struct node* printstack = head;
    while (printstack != NULL){
        printf("%d", printstack->data);
        printstack = printstack->next;
    }
}

int main(){
  
    push(3);
    push(8);
    push(7);
    pop();
    PrintStack();


}