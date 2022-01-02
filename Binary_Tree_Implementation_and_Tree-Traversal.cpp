#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node *create(node *root)
{
    node *newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    newnode -> left = NULL;
    newnode -> right = NULL;
    int x;
    cout << "Enter the data :: " << endl;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        newnode -> data = x;
        newnode -> left = create (root);
        newnode -> right = create (root);
    }
    return newnode;
}
void inorder(node *n)
{
    if (n != NULL)
    {
        inorder(n -> left);
        cout << "\t" << n -> data;
        inorder(n -> right);
    }
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << "\t" << root -> data;
        preorder(root -> left);
        preorder(root -> right);
    }
}
void postorder (node *root)
{
    if (root != NULL)
    {
        postorder (root -> left);
        postorder (root -> right);
        cout << "\t" << root -> data;
    }
}
int main()
{
    node *root = NULL;
    cout << "Enter -1 to detect the null " << endl;
    root = create (root);
    cout << "The data stored in root is " << root -> data << endl;
    cout << "The address of the root is " << root << endl;
    cout << "The inorder travrsal is" << endl;
    inorder (root);
    cout << endl;
    cout << "Inorder travrsal is done!!!!"<< endl;
    cout << "The preorder traversal is" << endl;
    preorder (root);
    cout << endl;
    cout << "The preorder traversal is done!!!!" << endl;
    cout << "The postorder traversal is " << endl;
    postorder (root);
    cout << endl;
    cout << "The postorder traversal is done!!!" << endl;
    return 0;
}