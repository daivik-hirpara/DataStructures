#include<iostream>
using namespace std;

class node 
{
    public:
        int data;
        int height;
        node* left;
        node* right;

    node(int val)
    {
        data = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};
int h(node* n)
{
    if(n==NULL)
    return 0;
    return n->height;
}
int balancefactor(node* n)
{
    if(n==NULL)
    return 0;

    return h(n->left)-h(n->right);
}
node* rr(node* a)
{
    node* b = a->left;
    node* c = b->right;

    b->right=a;
    a->left =c;

    a->height = max(h(a->right), h(a->left)) + 1;
    b->height = max(h(b->right), h(b->left)) + 1;
 
    return b;
}
node* lr(node* a)
{
    node* b = a->right;
    node* c = b->left;

    b->left=a;
    a->right=c;

    a->height = max(h(a->right), h(a->left)) + 1;
    b->height = max(h(b->right), h(b->left)) + 1;
 
    return b;
}
node* create_tree(node* root,int val)
{
    node* new_node = new node(val);

    if(root==NULL)
    return new_node;

    if(val<root->data)
    root->left=create_tree(root->left,val);
    else if(val>root->data)
    root->right=create_tree(root->right,val);

    root->height = max(h(root->left),h(root->right))+1;
    int bf = balancefactor(root);

    if(bf>1 && val < root->left->data)
    {
        return rr(root);
    }
    if(bf<-1 && val > root->right->data)
    {
        return lr(root);
    }
    if(bf>1 && val > root->left->data)
    {
        root->left = lr(root->left);
        return rr(root);
    }
    if(bf<-1 && val < root->right->data)
    {
        root->right = rr(root->right);
        return lr(root);
    }
    return root;
}
node* tree_min(node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
node* del(node* root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = del(root->left, val);
    else if (val > root->data)
        root->right = del(root->right, val);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            node* temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            node* temp = tree_min(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }

    if (root == NULL)
    return root;
    root->height = 1 + max(h(root->left), h(root->right));
    int bf = balancefactor(root);

    if (bf > 1 && balancefactor(root->left) >= 0)
    {
        return rr(root);
    }
    if (bf > 1 && balancefactor(root->left) < 0)
    {
        root->left = lr(root->left);
        return rr(root);
    }
    if (bf < -1 && balancefactor(root->right) <= 0)
    {
        return lr(root);
    }
    if (bf < -1 && balancefactor(root->right) > 0)
    {
        root->right = rr(root->right);
        return lr(root);
    }
    return root;
}
void inorder(node *root)
{
    if(root != NULL)
    {
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    node* root = NULL;
    int a, value;

    do {
        cout << "Press 1: Create Tree" << endl;
        cout << "Press 2: Delete Node" << endl;
        cout << "Press 3: Display Tree" << endl;
        cout << "Press 4: Exit" << endl;
        cout << "Enter key: ";
        cin >> a;
        switch (a) 
        {
            case 1:
                cout << "Enter a value ";
                cin >> value;
                root = create_tree(root, value);
                break;

            case 2:
                cout << "Enter a value to delete: ";
                cin >> value;
                root = del(root, value);
                break;

            case 3:
                cout << "Tree in inorder Traversal: " << endl;
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Invalid choice entered" << endl;
        }
    } 
    while (a != 4);

    return 0;
}