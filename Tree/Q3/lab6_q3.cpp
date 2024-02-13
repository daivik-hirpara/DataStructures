#include <iostream>
using namespace std;

class node 
{
    public:
        int data;
        node* left;
        node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* create_tree(node* root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) 
    {
      return NULL;
    }

    cout << "Enter data for left of " << data << endl;
    root->left = create_tree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = create_tree(root->right);
    return root;

}

int identical(node* x,node* y)
{
    if(x==NULL && y==NULL)
    return 1;

    if(x!=NULL && y!=NULL)
    {
        return((x->data==y->data) && identical(x->left,y->left) && identical(x->right,y->right));
    }

    return 0;
}

int main()
{
    node* roota= NULL;
    node* rootb= NULL;
    cout<<"Enter value for 1st tree"<<endl;
    roota = create_tree(roota);
    cout<<"Enter value for 2nd tree"<<endl;
    rootb = create_tree(rootb);

    if(identical(roota,rootb))
    cout<<endl<<"Entered trees are identical "<<endl;
    else
    cout<<endl<<"Entered trees are Not identical "<<endl;

    return 0;
}