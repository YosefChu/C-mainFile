#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
void insert(Node *root, int data)
{
    if(root->data>data)
    {
        if(root->left==NULL)
        {
            root->left = new Node(data);
        }
        else
        {
            insert(root->left, data);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right = new Node(data);
        }
        else
        {
            insert(root->right, data);
        }
    }
}
int main()
{
    Node *root = new Node(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    return 0;
}
