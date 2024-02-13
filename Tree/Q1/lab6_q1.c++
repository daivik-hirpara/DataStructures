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

void pre(node *temp)
{
  if (temp != NULL)
   {
    cout<< temp->data;
    pre(temp->left);
    pre(temp->right);
  }
}

void in(node *temp) 
{
  if (temp != NULL) 
  {
    in(temp->left);
    cout<< temp->data;
    in(temp->right);
  }
}

void post(node *temp)
 {
  if (temp != NULL)
  {
    post(temp->left);
    post(temp->right);
    cout<<temp->data;
  }
}
          
int tree_height(node* root)
{
    if(root == NULL) 
    return 0;
    else 
    {
        int lh = tree_height(root->left);
        int rh = tree_height(root->right);
         
        return max(lh, rh) + 1;
    }
}

int main()
{
    node* root = NULL;
    int a;
    cout<<"Press 1: create tree"<<endl;
    cout<<"Press 2: inoder"<<endl;
    cout<<"Press 3: preoder"<<endl;
    cout<<"Press 4: postoder"<<endl;
    cout<<"Press 5: height"<<endl;
    cout<<"Press 6: Exit"<<endl;
   
    do {
        
        cout<<"Enter your choice : "<<endl;
        cin>>a;
        switch (a) 
        {
        
            case 1:
            {
                root=create_tree(root);
                break;
            }
            case 2:in(root) ;
                break;
            case 3:pre(root) ;
                break;
            case 4:post(root);
                break;
            case 5:
                {
                  int v = tree_height(root);
                  cout<<"Height of the tree is "<<v<<endl;
                  break;
                }
            case 6: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=6);
    return 0;

  
}