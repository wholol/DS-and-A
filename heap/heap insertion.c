#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void insert(int A[], int key)             //let key be index insertion. to insert a heap, start from bottom (leaf)
{
  int i = key;        //let increment start from size - 1
  int temp;

  while (i > 0){        //while i is not the root node
    if (A[(i - 1)/2] < A[i])        //if parent is smaller than child
    {
        temp = A[(i-1)/2];        //store parent variable
        A[(i-1)/2] = A[i];  //let parent palce be child
        A[i] = temp;        //let child place be parent.
        i = (i - 1)/2;          //check the next parent.
    }

    else {
        break;
    }
     
    }   
}

void createheap(int A[],int n){
    for (int i = 1 ; i < n; i++){
        insert(A,i);
    }
}


void deleteheap(int A[],int n)
{

int key = n - 1;
int i = 0;
int store_root;
        
   
    A[0] = A[key];          //let end of heap be root.

    while(((2*i) + 2) <= key){           //the children, i cannot have children IF it is smaller than the end element of the array

        bool ltraverse = false;
        bool rtraverse = false;

        if (A[(2*i) + 1] > A[(2*i) + 2]){       //if left child is larger than right child
            if (A[(2*i) + 1] > A[i]){           //if left child is larger than parent
            ltraverse = true;
            store_root = A[i];
                A[i] = A[(2*i) + 1];            //let parent be left child value.
                A[(2*i) + 1] = store_root;      //let left child be parent value
                i = 2*i + 1;                    //traverse the parent to the left child
            }
        }

        if (A[(2*i) + 2] > A[(2*i) + 1]){       //if right child is larger than left child

            if (A[(2*i) + 2] > A[i]){       //if right child is larger than parent
            rtraverse = true;
                store_root = A[i];
                A[i] = A[(2*i) + 2];            //let parent be right child value.
                A[(2*i) + 2] = store_root;      //right child be parent
                i = 2*i + 2;                    //traverse the parent to be right child value.
            }
        }

        if (ltraverse == false && rtraverse == false){
            break;
        }
    }
}
   


void print(int A[],int n){
for (int i = 0; i < n; i++){
        printf("%d",A[i]);
        printf(" ");
    }
}

int main(){
    int A[] = {10,20,30,25,5,40,35};
    int n = (sizeof(A)/sizeof(A[0]));
    createheap(A,n);  //    after creating heap, A = {40 25 35 10 5 20 30}
    deleteheap(A,n);
    print(A,n);
   
}