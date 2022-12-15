#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *tail;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

// to count total number of elements in LL
int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// here we will compare each element with minimum element and
// change the value of min to the greater element its finds
// so at the end we will have the greatest element.
int max(struct Node *p)
{
    int m = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// simply iteration through linked list using while loop
int LinearSearch(struct Node *p, int x)
{
    bool search = false;
    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << "Element found" << endl;
            search = true;
            break;
        }
        p = p->next;
    }
    if (search == false)
    {
        cout << "Element isn't found" << endl;
    }
}

struct Node *Lsearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insertNode(struct Node *p, int ele, int pos)
{
    // to check whether the pos entered valid or not.
    if (pos < 0 || pos > count(p))
    {
        return;
    }
    // creating node
    struct Node *t;
    t = new Node;
    t->data = ele;

    // to insert node at the head
    if (pos == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void sortedInsert(struct Node *p, int x)
{
    struct Node *t;
    t = new Node;
    t->data = x;
    struct Node *q = NULL;

    // if the LL is empty
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        // to handle special case i.e. if entered element is the smallest
        if (p == head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void deleteNode(struct Node *p, int x)
{
    struct Node *q = NULL;
    if (head->data = x)
    {
        q = head;
        head = head->next;
        delete q;
    }
    while (p != NULL)
    {
        if (p->data == x)
        {
            q->next = p->next;
            delete p;
        }
        q = p;
        p = p->next;
    }
}

bool checkSorted(struct Node *p)
{
    int x = -32768;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void removeDuplicate(struct Node *p)
{
    struct Node *q;
    q = new Node;
    q = head->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverseList(struct Node *p){
    struct Node *q,*r;
    q = new Node;
    r = new Node;
    q,r = NULL;
    while(p!= NULL){
        r=q;
        q=p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15, 22, 26};
    create(A, 7);

    // Display(head);

    // cout<<"Number of nodes is "<<count(head)<<endl;

    // cout<<"Sum of node's data is "<<sum(head)<<endl;

    // cout<<"max element is "<<max(head)<<endl;

    // LinearSearch(head,100);

    // insertNode(head,16,5);

    // sortedInsert(head,18);

    // deleteNode(head, 10);

    // cout<<checkSorted(head);

    // removeDuplicate(head);

    reverseList(head);
    Display(head);
}