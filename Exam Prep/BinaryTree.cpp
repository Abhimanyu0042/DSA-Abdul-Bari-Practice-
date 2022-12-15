#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node *buildtree(node *root)
{
    cout << "Enter the data: " << endl;
    int d;
    cin >> d;
    root = new node(d);

    if (d == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << d << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << d << endl;
    root->right = buildtree(root->right);

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data<<" ";

}

int main()
{
    node *root = NULL;

    // create a tree
    root = buildtree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    preorder(root);
}
