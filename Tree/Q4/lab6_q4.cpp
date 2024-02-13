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

node* insert(node* root, int val)
{
    if (val == -1)
        return root;

    node* new_node = new node(val);
    if (root == NULL)
        return new_node;

    if (val < root->data)
        root->left = insert(root->left, val);

    if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

node* search(node* root, int key)
{
    if (root == NULL || key == root->data)
        return root;

    else if (key < root->data)
        return search(root->left, key);

    else if (key > root->data)
        return search(root->right, key);
}

node* tree_min(node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node* tree_max(node* root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node* successor(node* root, node* x)
{
    if (x == NULL)
        return NULL;

    if (x->right != NULL)
    {
        x = x->right;
        while (x->left != NULL)
        {
            x = x->left;
        }
        return x;
    }

    node* s = NULL;
    while (root != NULL)
    {
        if (x->data < root->data)
        {
            s = root;
            root = root->left;
        }
        else if (x->data > root->data)
            root = root->right;
        else
            break;
    }
    return s;
}

int main()
{
    node* root = NULL;
    int a;
    cout<<"Press 1: create tree"<<endl;
    cout<<"Press 2: Search key"<<endl;
    cout<<"Press 3: Tree Min and Tree Max"<<endl;
    cout<<"Press 4: Successor"<<endl;
    cout<<"Press 5: Exit"<<endl;
   
    do {
        
        cout<<"Enter your choice : "<<endl;
        cin>>a;
        switch (a) 
        {
        
            case 1:
            {
                cout << "Enter values and enter -1 to stop" << endl;
                int val = 0; 
                while (val != -1)
                {
                   cin >> val;
                   root = insert(root, val);
                }
                break;
            }
            case 2:
            {   
                int key;
                cout << endl << "Enter key" << endl;
                cin >> key;
                if (search(root, key) != NULL)
                cout << "Key found" << endl;
                else
                cout << "Key not found" << endl;
                break;
            }    
            case 3:
            { 
                node* x;
                node* y;
                x = tree_min(root);
                y = tree_max(root);
                cout << "Maximum node of the tree: " << y->data << endl;
                cout << "Minimum node of the tree: " << x->data << endl;
                break;
            }
            case 4:
            {       
                cout << "Enter value to find successor" << endl;
                int v;
                cin >> v;
                node* b = search(root,v);
                node* z = successor(root, b);
                if (z != NULL)
                cout << "Successor of entered node is: " << z->data << endl;
                else
                cout << "No successor found for the entered node" << endl;
                break;
            }
            case 5: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=5);
    return 0;
}
