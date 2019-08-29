#include <stdio.h>

#define SIZE 10

int hash[SIZE] = {0};       //index for hash


int hashfunc(int key){
    return key%SIZE;
}

int quadhashfunc(int index){
    int i = 0;
     while (hash[(index + i*i)%SIZE] != 0){     //only difference from linear probing is this function
            i = i + 1;
        }
    return (index + i)%SIZE;
}


void insertkey(int key){
    int index = hashfunc(key);      //let index be key%SIZE

    if (hash[index] != 0){
        int newindex = quadhashfunc(index);
        hash[newindex] = key;
    }

    else{
        hash[index] = key;
    }

    if (index == SIZE){
        printf("%d, no more space");
    }
}

void printlist(){
for (int i = 0 ; i < SIZE; ++i)
{
    printf("%d",hash[i]);
    printf(" ");
}
}

void quadhashfuncsearch(int searchindex,int key){        //searching for linear hash func
    int i = 0;
    while (hash[(searchindex + i*i)%SIZE] != key && (searchindex + i*i)%SIZE != SIZE){
        i = i + 1;
        if (hash[(searchindex + i*i)%SIZE] == key){
            printf("%d",key);
            printf(" ");
            printf("%d", (searchindex + i*i)%SIZE);
        }

        else{
             printf("key not found");
             break;
        }
    }

   
 
}

void search(int key){
    int searchindex = hashfunc(key);
    if (hash[searchindex] != key){      //if searchindex is not the key
        quadhashfuncsearch(searchindex,key);
    }
    else{
        if (hash[searchindex] == key){
            printf("%d", key);
            printf("");
            printf("%d", searchindex);
        }
    }

}

int main(){

insertkey(12);
insertkey(25);
insertkey(35);
insertkey(26);
printlist();
search(2);





}