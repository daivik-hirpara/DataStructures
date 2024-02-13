#include<iostream>
using namespace std;
void push(int value);
void display();
void pop();
void peek();
void isempty();
void isfull();

int stack[100];
int n;
int top = -1;

int main()
{
    int choice, value;
   
    
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
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            isempty();
            break;
        case 5:
            isfull();
            break;
        case 6:
            display();
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

void push(int value)
{
   
    if(top == n-1)
    cout<<"Stack overflow"<<endl;

    else
    {
        top = top + 1;
        stack[top]=value;
        cout<<"Node is inserted"<<endl;

    }

}

void pop()
{
    if(top == -1)
    cout<<"Stack underflow"<<endl;

    else
    {
        int x =stack[top--];
        cout<<"Popped element is "<<x<<endl;
    }


}
void peek()
{ 

     if(top == -1)
    cout<<"Stack underflow"<<endl;

    else
    {
        int x =stack[top];
        cout<<"Top most element is "<<x<<endl;
    }

}


void isempty()
{
    if(top<0)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    cout<<"Stack is Not empty"<<endl;
}


void isfull()
{
    if(top>=n-1)
    {
        cout<<"Stack is full"<<endl;
    }
    else
    cout<<"Stack is Not full "<<endl;
}

void display()
{
    for(int i=top;i>=0;i--)
    cout<<stack[i]<<" ";

    cout<<endl;

    if(top == -1)
    cout<<"Stack underflow"<<endl;

}