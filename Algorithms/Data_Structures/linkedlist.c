#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}node;

void insert_end(node* head, int val){
    // create a new node to be added to the list
    node* new_node = (struct Node*) malloc(sizeof(node));
    new_node->val = val;
    new_node->next = NULL; 

    // create a pointer for traversing the linked list from the start
    node* temp = head;
    // traversing to the end of the linked list
    while(temp != NULL){
        temp = temp->next;
    }
    // add the new node to the end of the linked list
    temp->next = new_node;
}


void insert_beginning(node* head, int val){
    // create a new node to be added into the list;
    node* new_node = (struct Node*) malloc(sizeof(node));
    new_node->val = val;
    new_node->next = NULL;

    // append the new node to the head of the linked list
    new_node->next = head;
    // move the pointer from previous head to the new head
    head = new_node;
}

void delete_node(node* head, int val){
    // create a pointer to traverse the linked list
    node* temp = head;
    while(temp != NULL){
        /*
        checking if the next node has the value or not, 
        so that this previous element can be reassigned a new next node after deletion
        */ 
        if(temp->next->val == val)break;
        temp = temp->next;
    }

    // if we reached the end of the linked list without finding the element, exit
    if(temp == NULL)return;

    // storing next of the node to be deleted so that after deletion the previous node's next can be updated
    node* temp1 = temp->next->next;
    // delete the node 
    free(temp->next);

    // reassign a the node next of the deleted node to the deleted node's previous node
    temp->next = temp1;
}


void delete_node_last(node* head){
    // if the linked list is empty, exit
    if(head == NULL)return;
    // create a pointer to traverse to the end of linked list
    node* temp = head;
    // traverse to the last node 
    while(temp->next != NULL){
        temp = temp->next;
    }

    // delete the last node
    free(temp);
    // no reassignment of next pointer of a node needed as no elements after the last element
}

void delete_node_first(node* head){
    // if linked list is empty, exit
    if(head == NULL)return;

    // temporarily store a pointer to the next element of head
    node* temp = head->next;

    // delete the old head
    free(head);

    // reassign the head pointer to the new head which is the next node of the old head
    head = temp;
}


void display(node* head){
    // a pointer for traversing the linked list from head till end
    node* temp = head;
    while(temp !=NULL){
        // printing the current node's value
        printf("%d ",temp->val);
        temp = temp->next;
    }
}

/*
Reverses the linked list by dfs
*/
node* reverse_list(node* head){
    // if there is only one element in the linked list, exit
    if(head == NULL || head->next == NULL)return;

    node* rest = reverse_list(head->next);

    head->next->next  = head;
    head->next = NULL;
    return rest;
}







int main(){

    return 0;

}

