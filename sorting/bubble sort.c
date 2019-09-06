#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void bubblesort(int A[], int n){

int temp;

for (int i = 0; i < n - 1; i++)     //for n - 2 passes (since it starts from zero)
{
   bool flag = false;
    for (int k = 0; k < n - 1 - i; k++){        //for each element
        if (A[k] > A[k + 1]){
            temp = A[k];
            A[k] = A[k + 1];
            A[k+1] = temp;
            flag = true;
        }
    }
    if (flag == false){
            break;
        }
}


}

void printArray(int A[], int n){
    for (int i = 0; i < n; ++i)
    {
        printf("%d",A[i]);
        printf(" ");

    }
}


int main(){

int A[] = {9,6,32,4,7,2,8};
 
int n = sizeof(A)/sizeof(A[0]);

bubblesort(A,n);

printArray(A,n);


}