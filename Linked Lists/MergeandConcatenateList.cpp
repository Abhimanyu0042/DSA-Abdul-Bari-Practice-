#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL,*second = NULL, *third = NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *tail;
    first = new Node;
    first->data = A[0];
    first -> next = NULL;
    tail = first;

    for(i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }

}

void create2(int A[], int n){
    int i;
    struct Node *t, *tail;
    second = new Node;
    second->data = A[0];
    second -> next = NULL;
    tail = second;

    for(i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }

}

void concat(struct Node *p, struct Node *q){
    third = p;
    while(p->next !=NULL){
        p=p->next;
    }
    p->next = q;
}

void mergeList(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        third -> next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        third -> next = NULL;
    }
    while(p != NULL && q != NULL){
        if(p->data < q->data){
            last ->next = p;
            last =p;
            p=p->next;
            last->next = NULL;
        }
        else{
            last ->next = q;
            last = q;
            q=q->next;
            last->next = NULL;

        }
    }
    if(p!=NULL){
        last->next = p;
    }
    if(q!=NULL){
        last->next = q;
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
    int A[] = {10,20,30,40,50};
    int B[] = {5,15,25,35,45};
    create(A,5);
    create2(B,5);

    // concat(first,second);
    // Display(third);

    // Display(first);
    // Display(second);

    mergeList(first,second);
    Display(third);
}

