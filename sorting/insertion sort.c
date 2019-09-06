#include <stdlib.h>
#include <stdio.h>


void insertionSort(int A[],int n){

int j ;

for (int i = 1 ; i < n; i ++){
    j = i - 1;
    int key = A[i];

    while (j >=0 && A[j] > key){
        A[j + 1] = A[j];
        j -= 1;
    }
    A[j + 1] = key;
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
insertionSort(A,n);
printArray(A,n);
}