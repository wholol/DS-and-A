#include <stdio.h>
#include <stdlib.h>



void merge(int l,int r, int middle,int A[]){        //l = left hadn side, r = right hand side, middle = middle of array.
int i = 0;              //subarray inrement
int j = 0;              //subarray increment
int k = l;              //merged array increment (technically main array)
int leftsublength = middle - l + 1;
int rightsublength = r - middle;
int leftsubarray[leftsublength];                   
int rightsubarray[rightsublength];



for (int z = 0 ; z < leftsublength; z++){           //fill left subarray will the desired values (from value l to middle)
        leftsubarray[z] = A[z + l];
}


for (int y = 0; y < rightsublength; y++){
    rightsubarray[y] = A[y + middle + 1];
}

while (i < leftsublength && j < rightsublength){
    if (leftsubarray[i] < rightsubarray[j]){
        A[k] = leftsubarray[i];
        k  = k + 1;
        i  = i + 1;
    }

    if (rightsubarray[j] < leftsubarray[i]){
        A[k] = rightsubarray[j];
        k = k + 1;
        j = j + 1;
    }
}

while (i < leftsublength){
         A[k] = leftsubarray[i];
         k  = k + 1;
         i = i +  1;
    }

    while (j < rightsublength){
         A[k] = rightsubarray[j];
         k = k + 1;
         j = j + 1;
    }

}


void mergesort(int l,int r, int A[]){


if (l < r){     //while the left hand is smalelr than right

    int middle = l+(r-l)/2; 
    mergesort(l,middle,A);          // from low to midd
    mergesort(middle + 1, r, A);    //from middle to right
    merge(l,r,middle,A);            //passes in the left postion of the low,right, middle position of the array.
                                    //essentially splits it into two,
}
    
}

void printArray(int A[],int n){
    for (int i = 0 ; i < n; i++){
        printf("%d",A[i]);
        printf(" ");
    }
}


int main(){
int A[] = {90,60,23,101,4};
int n = sizeof(A)/sizeof(A[0]);
mergesort(0,n-1,A);
printArray(A,n);




}