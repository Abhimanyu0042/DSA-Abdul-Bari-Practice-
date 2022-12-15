#include <iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*head = NULL;

void create(int A[],int n){
    struct Node *t,*tail;
    head = new Node;
    head ->data = A[0];
    head -> next = NULL;
    head->prev = NULL;

    for(int i = 0;i<n;i++){
        t = new Node;
        t -> data = A[i];
        t->next = tail->next;
        t->prev = tail;
        tail->next = t;
        tail = t;

    }
}