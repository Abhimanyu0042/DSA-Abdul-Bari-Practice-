#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    struct Node *t, *tail;
    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}
int Length(struct Node *p)
{
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

// this code to insert in circular linked list is similar to normal linked list
void insert(struct Node *p, int pos, int ele)
{
    // to check whether the pos is valid or not
    if (pos < 0 || pos > Length(head))
    {
        return;
    }

    // if i want to put the node before head however in circular LL its
    // same as putting at the tail of LL
    if (pos == 0)
    {
        struct Node *t;
        t = new Node;
        t->data = ele;
        // if head is the first node to enter
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        struct Node *t;
        t = new Node;
        t->data = ele;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int pos)
{
    int x,i;
    //to check whether the position is valid or not
    if (pos < 0 || pos > Length(head))
    {
        return 0;
    }
    struct Node *q;
    if (pos == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else{
        for(i=1;i<pos-2;i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    create(A, 6);

    Display(head);

    insert(head, 3, 12);
    
    Display(head);

    Delete(head,1);

    Display(head);
}