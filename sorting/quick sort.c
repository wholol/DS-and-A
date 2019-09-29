#include <stdlib.h>
#include <stdio.h>


int partition(int A[], int start, int end){                        //partitioning: process to select index

int pivot = A[start];           //store the pivot value
int i = start;                  //
int j = end;

    while (A[i] <= pivot){   //while the i index is smaller than the pviot value
        i += 1;             //increment i
    }

    while (A[j] > pivot){   
        j -= 1;
    }

    if (i < j){
    int temp1 = A[i];   //swap A[i] and A[j]
    A[i] = A[j];
    A[j] = temp1;
    }

    if (j < i){
        int temp2 = A[j];
        A[j] = pivot;
        A[start] = temp2;
        return j;
    }
}


void QuickSort(int A[], int start,int end){

    if (start > end){           //this condition is not valid   
        return;
    }
        int partitionindex = partition(A,start,end);
        QuickSort(A,start,partitionindex - 1);      //sort the right hand side
        QuickSort(A,partitionindex + 1,end);        //sort the left hand side 
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
QuickSort(A,0,n-1);
printArray(A,n);
}