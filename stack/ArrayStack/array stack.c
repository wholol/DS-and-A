#include <stdio.h>
#include <stdlib.h>


#define size 100

int stack[size];

int top = - 1;

void push(int x){

    top = top + 1;
    stack[top] = x;
}

void pop(){
    if (top == -1){
    printf("already empty.");
        return;
    }

    else{
        top = top - 1;
    }
}

void display(){
    if (top == -1){
        printf("empty");
        return;
    }
    for (int i = 0; i <= top; i++){
        printf("%d",stack[i]);
        printf(" ");
    }
}

int main(){
    push(47);
    push(8);
    push(3);
    push(90);
    pop();
    display();
}