#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;


Node* create(int data){
    Node* node = (struct Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data)
{
    if(root == NULL){
        return create(data);
    }
    if(data< root->data)root->left = insert(root->left, data);
    else if(data > root->data)root->right = insert(root->right, data);
    return root;
}

int findKthSmallestNode(Node* root, int* k){
    if(root == NULL)return -1;
    int left = findKthSmallestNode(root->left, k);
    if(left != -1)return left;

    (*k)--;

    if(*k == 0)return root->data;
    return findKthSmallestNode(root->right, k);
}

int findKthSmallestNodeHelper(Node* root, int k){
    return findKthSmallestNode(root, &k);
}


int main(){
    int data;
    Node* root = NULL;
    while(1){
        scanf("%d",&data);
        if(data == -1)break;
        root =  insert(root, data);
    }
    int k;
    scanf("%d",&k);
    printf("%d \n",findKthSmallestNodeHelper(root, k));
    return 0;
}