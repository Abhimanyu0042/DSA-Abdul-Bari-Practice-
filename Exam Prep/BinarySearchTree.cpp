#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
};

bool searchinBST(Node* &root,int x){
    if (root == NULL){
        return false;
    }
    if (root->data == x){
        return true;
    }

    if (root->data > x){
        return searchinBST(root->left,x);

    }
    else{
        return searchinBST(root->right,x);
    }
}



Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp -> left;

    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp -> right;

    }
    return temp;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* deleteFromBST(Node* root,int val){
    if (root == NULL){
        return root;
    }
    if (root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child

        // left child
        if( root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // right child

         if( root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child 
        if(root -> left != NULL && root -> right != NULL){
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root->right,mini);
            return root;
        }
        

    } 
    else if( root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
     else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }


}

int main()
{
    Node* root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    int x;
    cout << "Search the element in BST" << endl;
    cin >> x;

    searchinBST(root,x);

    cout << "Min Value is: " << minVal(root)-> data << endl;
    cout << "Max Value is: " << maxVal(root)-> data << endl;


    return 0;
}