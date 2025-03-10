#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 10000;
int queue_[MAX_SIZE];

int front = 0, rear = -1;

int peek(){
    return queue_[front];
}
int isfull(){
    return rear >= MAX_SIZE - 1;
}

int isempty(){
    return front<0;
}

int enqueue(int item){
    if(isfull())return 0;
    rear++;
    queue_[rear] = item;
    return 1;
}

int dequeue(){
    if(isempty())return 0;
    int data = queue_[front];
    front++;
    return data;
}


int main()
{
int n;
scanf("%d", &n);


for(int i = 0 ; i < n; i++){
    int x;
    scanf("%d", &x);
    enqueue(x);
}

for(int i = 0 ;i < n; i++){
    printf("%d ", dequeue());
}

printf("\nDONE!\n");
return 0;
}