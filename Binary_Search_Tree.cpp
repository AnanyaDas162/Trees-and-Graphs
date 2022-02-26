#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node *root = NULL;
int x;
node *newnode = NULL;
node *create_node (node *n, int a)
{
    newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> data = a;
    return newnode;
}
node *insert_node (node *n, int a)
{
    if (root == NULL)
    {
        root = newnode;
        n = root;
    }
    else if (n -> left == NULL && n -> right == NULL && a < n -> data)
    {
        n -> left = newnode;
    }
    else if (n -> right == NULL && n -> left == NULL && a > n -> data)
    {
        n -> right = newnode;
    }
    else if (n -> left == NULL && n -> right != NULL)
    {
        if (a < n -> data)
        {
            n -> left = newnode;
        }
        else
        {
            n -> right = insert_node (n -> right, a);
        }
    }
    else if (n -> left != NULL && n -> right == NULL)
    {
        if (a > n -> data)
        {
            n -> right = newnode;
        }
        else
        {
            n -> left = insert_node(n -> left, a);
        }
    }
    else if (a < n -> data)
    {
        n -> left = insert_node (n -> left, a);
    }
    else if (a > n -> data)
    {
        n -> right = insert_node (n -> right, a);
    }
    return n;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder (root -> left);
        cout << "\t" << root -> data;
        inorder (root -> right);
    }
}
void preorder (node *root)
{
    if (root != NULL)
    {
        cout << "\t" << root -> data;
        preorder (root -> left);
        preorder (root -> right);
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
    int choice = 1;
    while (choice)
    {
        cout << "Enter 1 for the insertion of new node " << endl;
        cout << "Enter 2 for inorder traversal " << endl;
        cout << "Enter 3 for preorder traversal " << endl;
        cout << "Enter 4 for postorder traversal " << endl;
        cout << "Enter 0 for the end of program " << endl;
        cout << "Enter your choice :: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the data :: " << endl;
            cin >> x;
            newnode = create_node (root, x);
            root = insert_node (root, x);
        }
        else if (choice == 2)
        {
            cout << "The inorder traversal of the tree is " << endl;
            inorder (root);
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << "The preorder traversal of the tree is " << endl;
            preorder (root);
            cout << endl;
        }
        else if (choice == 4)
        {
            cout << "The postorder traversal of the tree is " << endl;
            postorder (root);
            cout << endl;
        }
        else if (choice == 0)
        {
            cout << "The program is ended" << endl;
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}