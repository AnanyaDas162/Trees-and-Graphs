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
vector <int> v;
queue <node*> q;
int level = 0;
void recursive_bfs (node* root){
    if (q.empty()){
        return;
    }
    node* temp = q.front();
    v.push_back (temp -> data);
    q.pop ();
    if (temp -> left){
        q.push (temp -> left);
    }
    if (temp -> right){
        q.push (temp -> right);
    }
    recursive_bfs (root);
}
int main()
{
    node *root = NULL;
    cout << "Enter -1 to detect the null " << endl;
    root = create (root);
    cout << "The data stored in root is " << root -> data << endl;
    cout << "The address of the root is " << root << endl;
    q.push (root);
    recursive_bfs (root);
    cout << "The BFS traversal is :: " << endl;
    for (int i = 0; i < v.size(); i ++){
        cout << v[i] << " ";
    }
    return 0;
}
