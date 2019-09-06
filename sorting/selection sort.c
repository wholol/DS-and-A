#include <stdlib.h>
#include <stdio.h>


void SelectionSort(int A[],int n){

int traverse, key;
int temp;
for (int i = 0; i < n - 1; i++){
    traverse = i;
    key = i;
    while (traverse < n - 1){
        if (A[traverse] < A[key]){
            key = traverse;
        }
        traverse = traverse + 1;
    }
    temp = A[key];
    A[key] = A[i];
    A[i] = temp;

}


}


void printArray(int A[],int n){
for (int i = 0; i < n; i ++){
    printf("%d",A[i]);
    printf(" ");
}

}

int main(){

int A[] = {8,6,3,23,7,90};

int n = sizeof(A)/sizeof(A[0]);
SelectionSort(A,n);
printArray(A,n);
}