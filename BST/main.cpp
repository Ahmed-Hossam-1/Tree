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
    node* searchTree(node* rootNode,int key)
    {
        if(rootNode == NULL)
        {
            return NULL;
        }
        else if(rootNode->data == key)
        {
            return rootNode;
        }
        else if(rootNode->data < key)
        {
            return searchTree(rootNode->right,key);
        }
        else if(rootNode->data > key)
        {
            return searchTree(rootNode->left,key);
        }
    }
    bool searchTree(int key)
    {
        node* result = searchTree(root,key);
        if(result == NULL)
        {
            cout<<"Not Found :("<<endl;
        }
        else
        {
            cout<<"Found :)"<<endl;
        }
    }

    node* findMax(node* rooNode)
    {
        if(rooNode == NULL)
        {
            return NULL;
        }
        else if(rooNode->right == NULL)
        {
            return rooNode;
        }
        else if(rooNode->right !=NULL)
        {
            return findMax(rooNode->right);
        }
    }

    node* findMin(node* rooNode)
    {
        if(rooNode == NULL)
        {
            return NULL;
        }
        else if(rooNode->left == NULL) // NULL == 0 //
        {
            return rooNode;
        }
        else if(rooNode->left !=NULL)
        {
            return findMin(rooNode->left);
        }
    }
    node* deleteNode(node* rootNode,int key)
    {
        if(rootNode == NULL)
        {
            return NULL;
        }
        else if(key < rootNode->data)
        {
            rootNode->left = deleteNode(rootNode->left,key);
        }
        else if(key > rootNode->data)
        {
            rootNode->right = deleteNode(rootNode->right,key);
        }
        else
        {
            if(rootNode->left == NULL && rootNode->right == NULL)
            {
                rootNode = NULL;
            }
            else if(rootNode->left != NULL && rootNode->right == NULL)
            {
                rootNode->data = rootNode->left->data;
                delete rootNode->left;
                rootNode->left=NULL;
            }
            else if(rootNode->left == NULL && rootNode->right != NULL)
            {
                rootNode->data = rootNode->right->data;
                delete rootNode->right;
                rootNode->right=NULL;
            }
            else
            {
                node* preMax= findMax(rootNode->left);
                rootNode->data=preMax->data;
                rootNode->left = deleteNode(rootNode->left,preMax->data);
            }

        }
        return rootNode;
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

    cout<<endl<<"============"<<endl;
    N.searchTree(10);
    N.searchTree(50);
    N.searchTree(4);
    cout<<endl<<"============"<<endl;
    node* valueMin = N.findMin(N.root);
    cout<<"MIN: "<<valueMin->data<<endl;
    node* valueMax = N.findMax(N.root);
    cout<<"MAX: "<<valueMax->data<<endl;
    cout<<endl<<"====== Deleted ======"<<endl;
    N.deleteNode(N.root,5);
    N.preOrder(N.root);

    return 0;
}
