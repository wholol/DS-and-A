#include <stdlib.h>
#include <stdio.h>


struct node{
    int data;
    struct node* next;
};


struct node* head = NULL;

struct node* insert(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}


void printnodes(struct node* head){
    
    if (head == NULL){
        printf("NULL");
        return;
    }
    printf("%d ->", head->data);
    printnodes(head->next);
    printf(" ");
}

void removenodes(int data){

struct node* prev = head;         //set remove to the head value.
struct node* temp = head->next;     //temp = node to be deleted


if (head->data == data){            //if the data is at the head itself
    head = prev->next;            //update head.
    free(prev);                   //free the orgial head node.
}

else{
    while (temp != NULL){         //while remove is not null
        temp = temp->next;      //traverse remove
        prev = prev->next;
        if (temp->data == data){  //if remove is the data
            prev->next = temp->next;  //set the previous node to the next of remove
            free(temp);           //free remove
            break;
        }
    }
}
}



int main(){
head = insert(head,5);
head = insert(head,6);
head = insert(head,7);
head = insert(head,8);
printnodes(head);
removenodes(6);
printnodes(head);

