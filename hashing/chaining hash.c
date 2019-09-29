#include <stdio.h>
#include <stdlib.h>

struct node* hashtable[10];     //an array of hashtable pointers of type struct node

struct node{
    int data;
    struct node* next;
};

int hashfunction(int data){     //hash function function
    return (data%10);
}

void SortedInsert(struct node** hash,int data){     //creates a new node, updates the hash pointer on its own.
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *hash;
    *hash = newnode;
    
  
    struct node* traverse = *hash;   //set traverse to point to hash.
    
    while (traverse != NULL)      //while the hash pointer is not null
    {
        int store_temp_data;
      
        if (data < traverse->data){                 //if the data is smaller the the traverse data
           store_temp_data = traverse->data;        //temporary store the traverse data in this variable
            (traverse->next)->data = store_temp_data;   //set the new next data to the previous node value
            traverse->data = data;                  //set the traverse data to the current value
        }
        
        traverse = traverse->next;          //traverse to the next value
    }
}

void insert(int data){      //inserts the data to the linkedlsit hash
    int index = hashfunction(data);
    SortedInsert(&hashtable[index],data);       //passes the address of the pointer variable.


}

void printtest()
{
    struct node* print = hashtable[5];

    while (print != NULL){
        printf("%d",print->data);
        printf(" ");
        print = print->next;
    }
}

int main(){

    for (int i = 0 ; i < 10; i++){
        hashtable[i] = NULL;
    }

    insert(5);
    insert(35);
    insert(95);
    printtest();







}