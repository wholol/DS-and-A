#include <stdlib.h>
#include <stdio.h>

//queue for graph. FIFO

struct node{
    int vertex;
    struct node* next;
};


struct node* head = NULL;
struct node* tail = NULL;

void enqueue(int vertex){               //enqueue
    struct node* createnode = (struct node*)malloc(sizeof(struct node));
    createnode->vertex = vertex;
    createnode->next = NULL;
    if (head == NULL && tail == NULL){      //if there are no elements in linked list
           head = createnode;
           tail = createnode;
    }
    else{
        tail->next = createnode;            //update the tail pointer to the newly created node if list is not empty
        tail = createnode;
    }
}

void dequeue(){     //dequeue
    if (head == NULL && tail == NULL){
        printf("empty list");
        return;
    }
    
    else{
    struct node* delete = head;
    head = delete->next;
    free(delete);
    }
}

void printqueue(){
    struct node* print = head;
    while (print != NULL){
        printf("%d ->",print->vertex);
        print = print->next;
    }
}


int main(){
enqueue(8);
enqueue(4);
enqueue(6);
enqueue(81);
dequeue();
printqueue();

}