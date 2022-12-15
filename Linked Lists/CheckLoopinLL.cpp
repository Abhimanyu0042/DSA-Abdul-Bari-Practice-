#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

//creating array into loop
void create(int A[], int n){
    struct Node *t,*tail;
    int i;
    head = new Node;
    head -> data = A[0];
    head -> next = NULL;
    tail = head;

    for(i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

//to check if its loop or not we will be using do-while loop
//here we will be using two pointers, incrementing them at different pace,
//if they meet again i.e. their data matches then its a loop
int isLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        if(q!=NULL){
        q=q->next;}
    }while(p && q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    struct Node *t1,*t2;
    int A[] = {10,20,30,40,50,60};
    create(A,6);
    // t1 = new Node;
    // t2 = new Node;

    // t1 = head->next->next;
    // t2 = head->next->next->next->next->next;
    // t2->next = t1; 
    
    cout<<isLoop(head);
    // Display(head);
}