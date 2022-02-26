#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node*left;
    struct node*right;
}node;
node *root_node = NULL;
void inorder(node *root)
{
    if (root == NULL) return;
    inorder(root -> left);
    cout << root -> data << "\t";
    inorder(root -> right);
}
void preorder (node *root)
{
    if (root == NULL) return;
    cout << root -> data << "\t";
    preorder(root -> left);
    preorder(root -> right);
}
void postorder (node *root)
{
    if (root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << "\t";
}
node *allocate_node(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> data = x;
    return newnode;
}
node *insert_node(node *parent, int value)
{
    if (parent == NULL)
    {
        parent = allocate_node(value);
    }
    else if(value < parent -> data)
    {
        parent -> left = insert_node(parent->left, value);
    }
    else if (value > parent -> data)
    {
        parent -> right = insert_node(parent-> right, value);
    }
    return parent;
}
bool find_value(int target, node *parent)
{
    if (parent == NULL)
    {
        return false;
    }
    else if (target == parent -> data)
    {
        return true;
    }
    else if (target > parent ->data)
    {
        return find_value(target, parent -> right);
    }
    else if (target < parent -> data)
    {
        return find_value(target, parent->left);
    }
}
node *find_max(node *root)
{
    if (root -> right == NULL)
    {
        return root;
    }
    else
    {
        return find_max(root-> right);
    }
}
node *find_min(node *root)
{
    if (root -> left == NULL)
    {
        return root;
    }
    else
    {
        return find_min(root -> left);
    }
}
int main()
{
    node *root = NULL;
    int choice = 1, target, key;
    while (choice)
    {
        cout << endl;
        cout << "Enter 1 to insert the new node"<<endl;
        cout << "Enter 2 for inorder traversal"<<endl;
        cout << "Enter 3 for preorder traversal"<<endl;
        cout << "Enter 4 for postorder traversal"<<endl;
        cout << "Enter 5 for finding a value in the BST" << endl;
        cout << "Enter 6 for finding the maximum value in the BST" << endl;
        cout << "Enter 7 for finding the minimum value in the BST"<< endl;
        cout << "Enter 0 to end the program "<< endl;
        cout << "Enter your choice"<<endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the data :: " << endl;
            int x;
            cin >> x;
             //parent = allocate_node(x);
            root = insert_node(root, x);
            root_node = root;
        }
        else if (choice == 2)
        {
            inorder(root);
        }
        else if(choice == 3)
        {
            preorder (root);
        }
        else if(choice == 4)
        {
            postorder (root);
        }
        else if (choice == 5)
        {
            cout << "Enter the target value for searching ::  " << endl;
            cin >> target;
            if (find_value(target, root))
            {
                cout << "****The target is FOUND in the BST*****" << endl;
            }
            else
            {
                cout << "*******NOT FOUND********"<< endl;
            }
        }
        else if (choice == 6)
        {
            cout << "The maximum value in the BST is ::  ";
            cout << (find_max(root)) -> data << endl;
        }
        else if (choice == 7)
        {
            cout << "The minimum value in the BST is :: ";
            cout << (find_min(root)) -> data << endl;
        }
        else if (choice == 0)
        {
            cout <<"The program is ended"<< endl;
        }
        else
        {
            cout << "Wrong Choice"<< endl;
        }
    }
    return 0;
}