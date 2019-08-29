#include <stdio.h>

#define SIZE 10

int hash[SIZE] = {0};       //index for hash


int hashfunc(int key){
    return key%SIZE;
}



void insertkey(int key){
    int index = hashfunc(key);      //let index be key%SIZE

    if (hash[index] != 0){
        int i = 0;
        while (hash[(index + i)%SIZE] != 0){
            i = i + 1;
        }
        hash[(index + i)%SIZE] = key;
    }

    else{
        hash[index] = key;
    }
}

int main(){

insertkey(12);
insertkey(25);
insertkey(35);
insertkey(26);

for (int i = 0 ; i < SIZE; ++i)
{
    printf("%d",hash[i]);
    printf(" ");
}



}