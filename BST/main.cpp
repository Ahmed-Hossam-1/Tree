#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }

};

class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    node* insertion(node *rootNode,int val)
    {
        if(rootNode == NULL)
        {
            node *newNode = new node(val);
            rootNode = newNode;
        }
        else if(val < rootNode->data)
        {
            rootNode->left = insertion(rootNode->left,val);
        }
        else
        {
            rootNode->right = insertion(rootNode->right,val);
        }
        return rootNode;
    }

    void insertion(int val)
    {
        root = insertion(root,val);
    }

    void preOrder(node* rootNode) // Root Left Right
    {
        if(rootNode == NULL) return;
        cout<<rootNode->data<<"\t";
        preOrder(rootNode->left);
        preOrder(rootNode->right);
    }
    void inOrder(node* rootNode) // Left Root  Right
    {
        if(rootNode == NULL) return;
        preOrder(rootNode->left);
        cout<<rootNode->data<<"\t";
        preOrder(rootNode->right);
    }
    void postOrder(node* rootNode) // Left Right Root
    {
        if(rootNode == NULL) return;
        preOrder(rootNode->left);
        preOrder(rootNode->right);
        cout<<rootNode->data<<"\t";
    }

};

int main()
{
    BST N;
    N.insertion(5);
    N.insertion(2);
    N.insertion(10);
    N.insertion(4);
    N.insertion(5);

    N.preOrder(N.root);
    return 0;
}
