#include <iostream>
using namespace std;


int top1 = -1;
int top2 = -1;
int top3 = -1;
int n;
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
node* stack1[100];
node* stack2[100];
node* stack3[100];

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
bool isempty1()
{
   return top1 == -1;
}
void push1(node* value)
{

        top1 = top1 + 1;
        stack1[top1]=value;
}
void pop1()
{
    if(!isempty1())
    {
       top1--;
    }
}
node* peek1()
{ 
    if(!isempty1())
    {
      return stack1[top1];
    }
}
bool isempty2()
{
   return top2 == -1;
}
void push2(node* value)
{

        top2 = top2 + 1;
        stack2[top2]=value;
}
void pop2()
{
    if(!isempty2())
    {
       top2--;
    }
}
node* peek2()
{ 
    if(!isempty2())
    {
      return stack2[top2];
    }
}
bool isempty3()
{
   return top3 == -1;
}
void push3(node* value)
{
        top3 = top3 + 1;
        stack3[top3]=value;

}
void pop3()
{
    if(!isempty3())
    {
       top3--;
    }
}
node* peek3()
{ 
    if(!isempty3())
    {
      return stack3[top3];
    }
}

void in(node* root)
{
    node* temp = root;

    while(temp!=NULL || !(isempty1()))
    {
        while(temp!=NULL)
        {
            push1(temp);
            temp = temp->left;
        }
        temp = peek1();
        pop1();
        cout<<temp->data<<" ";
        temp = temp->right;
    }

}

void pre(node* root)
{
    if(root == NULL)
    return;

    push2(root);
    while(!(isempty2()))
    {
        node* temp = peek2();
        cout<<temp->data<<" ";
        pop2();

        if(temp->right)
        push2(temp->right);
        if(temp->left)
        push2(temp->left);
    }
}

void post(node* root) 
{
    node* temp = root;
    node* prev = NULL;
    
    while (temp != NULL || !isempty3()) 
    {
        if (temp != NULL)
        {
            push3(temp);
            temp = temp->left;
        }
        else 
        {
            prev = peek3()->right;
            
            if (prev == NULL) 
            {
                prev = peek3();
                pop3();
                cout << prev->data << " ";
                
                while (!isempty3() && prev == peek3()->right) 
                {
                    prev = peek3();
                    pop3();
                    cout << prev->data << " ";
                }
            }
            else
            {
                temp = prev;
            }
        }
    }
}

int main()
{
    node* root = NULL;
    root = create_tree(root);
    cout<<"Inorder taversal"<<endl;
    in(root);

    cout<<endl<<"Preorder traversal"<<endl;
    pre(root);

    cout<<endl<<"Postorder traversal"<<endl;
    post(root);
}