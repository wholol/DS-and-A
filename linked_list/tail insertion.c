#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* tailinsert(int data, struct node* head){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));    
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)       //if the head is null
    {
        
        head = newnode;     //initialize the head at the first position
           
        return head;
    }

    else{
        struct node* traverse = head;       //let traverse ponit to head
        while(traverse->next != NULL)       //while the next pointer isnt null
        {
            traverse = traverse->next;
        }
        traverse->next = newnode;
    }

    return head;

}

void printlist(struct node* head){

    while (head != NULL){
        printf("%d",head->data);
        printf(" ");
        head = head->next;
    }
}

int main(){
head = tailinsert(10,head);
head = tailinsert(25,head);
    printlist(head);

}