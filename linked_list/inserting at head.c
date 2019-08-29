#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* insertnode(int data, struct node* head){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));    
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    return head;
}

void printlist(struct node* head){

    while (head != NULL){
        printf("%d",head->data);
        printf("");
        head = head->next;
    }
}

int main(){
    head = insertnode(10,head);
    head = insertnode(25,head);
    printlist(head);
}