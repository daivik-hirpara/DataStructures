#include<iostream>
using namespace std;

class Node
{

    public:
    int val;
    Node* next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class stack
{

    Node* top;
    public:
    stack()
    {
        top = NULL;
    }  

    int count = 1;
    void push(int data,int n)
    {
        Node* new_node = new Node(data);
        if (!new_node) 
        {
            cout << "Stack Overflow"<<endl;
            return;
        }
        if(count>n)
        { 
            
            cout << "Stack Overflow"<<endl;
            return;

        }
 

        if(top == NULL)
        {
            top = new_node;
            cout<<"Node is Inserted"<<endl;
            count++;
            return;
        }
        else
        {
        new_node->next = top;
        top = new_node;
        count++;
        }
        cout<<"Node is Inserted"<<endl;
    }

    void pop()
    {
        Node* temp =top;

        if(temp == NULL)
        {
            cout<<"Stack underflow"<<endl;
            return ;
        }

        else
        {
            top = top->next;
            cout<<"Poppped Element is "<<temp->val<<endl;
            free(temp);
            count--;
        }
    } 
    void isempty()
    {
        if(top == NULL)
        {
            cout<<"Stack is empty"<<endl;
            
        }
        else
        cout<<"Stack is Not empty"<<endl;
    }
    
    void isfull(int n)
    {
        if(count>n)
        cout<<"Stack is full"<<endl;
        else
        cout<<"Stack is not full"<<endl;
    }


    int peek()
    {
        if(top != NULL)
        return top->val;

        else
        return -1;
    }

    void display()
    {
        Node* temp = top;
        if(temp == NULL)
        {
            cout<<"Stack underflow"<<endl;
            return;
        }

        cout<<"The created Stack"<<endl;

        while(temp!=NULL)
        {
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        
        cout<<"NULL"<<endl;
    }

};


int main()
{
    stack s;
    int choice, value;
    int n;
    
    cout<<"Implementation of Stack using Linked List"<<endl;
    
    cout<<"Enter the predefined size of thr stack"<<endl;
    cin>>n;
    while (1) 
    {
        cout<<endl;
        cout<<"Press : 1 To Push"<<endl;
        cout<<"Press : 2 To Pop" <<endl;
        cout<<"Press : 3 To find peek "<<endl;
        cout<<"Press : 4 To find is empty"<<endl;
        cout<<"Press : 5 To find is full"<<endl;
        cout<<"Press : 6 To display"<<endl;
        cout<<"Press : 7 To Exit"<<endl;


        cout<<"Enter your choice : "<<endl;
        cin>>choice;



        switch (choice)
        {
        case 1:
            cout<<"Enter the value to insert: "<<endl;
            cin>>value;
            s.push(value,n);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout<<"Top most element of the stack is  "<<s.peek()<<endl;
            break;
        case 4:
            s.isempty();
            break;
        case 5:
            s.isfull(n);
            break;
        case 6:
            s.display();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"Wrong choice entered"<<endl;
           
        }
    }
    

 

    return 0;
}