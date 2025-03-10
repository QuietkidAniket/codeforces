#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 5;

int queue_[MAX_SIZE];

int front = -1, rear = -1;

int isempty(){
    return front == -1;
}

int isfull(){
    return (rear + 1)%MAX_SIZE == front;
}

int enqueue(int item){
    if(isfull())return -1;
    if(isempty())front = 0;
    rear = (rear+1)%MAX_SIZE;
    queue_[rear] = item;
    return 1;
}

int dequeue(){
    if(isempty())return 0;
    int item  = queue_[front];

    if(front == rear){
        front = -1;
        rear = -1;
    }else front = (front+1)%MAX_SIZE;
    return item;
}

void display(){
    printf("Queue:  ");
    if(isempty())return;   
    for(int i = front; i <rear; i = (i+1)%MAX_SIZE ){
        printf("%d ",queue_[i]);
    } 
}


int main()
{
int n;
scanf("%d", &n);


for(int i = 0 ; i < n; i++){
    int x;
    scanf("%d", &x);
    if(i == MAX_SIZE){
        dequeue();
    }
    enqueue(x);
}


for(int i = 0 ;i < n; i++){
    printf("%d ", dequeue());
}

printf("\nDONE!\n");
return 0;
}