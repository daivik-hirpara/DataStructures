#include<iostream>
using namespace std;
void push(int value);
void display();
void pop();
void peek();
bool isempty();
bool isfull();
int getmin();

int stack[100];
int minstack[100];
int n;
int top = -1;
int mintop = -1;

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
        cout<<"Press : 7 To get minimum"<<endl;
        cout<<"Press : 8 To exit"<<endl;


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
            if (isempty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
            break;
        case 5:
            if (isfull())
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
            break;
        case 6:
            display();
            break;
        case 7:
             if (isempty())
                cout << "Stack Underflow" << endl;
            else
                cout << "Minimum element in the stack: " << getmin() << endl;
            break;
        case 8:
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
    {
    cout<<"Stack overflow"<<endl;
    return ;
    }

   
        top = top + 1;
        stack[top]=value;
        cout<<"Node is inserted"<<endl;

   

    if(mintop == -1 || value<=minstack[mintop])
    {
        mintop++;
        minstack[mintop] = value; 
    }

}

void pop()
{
    if(top == -1)
    {
    cout<<"Stack underflow"<<endl;
    return;
    }

    else
    {
        int x =stack[top--];
        cout<<"Popped element is "<<x<<endl;


        if(x == minstack[mintop])
        mintop--;
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


int getmin()
{
    return minstack[mintop];
}


bool isempty()
{
     return (top == -1);  
}
bool isfull()
{
    return (top==n-1);
}
void display()
{
    for(int i=top;i>=0;i--)
    cout<<stack[i]<<" ";

    cout<<endl;

    if(top == -1)
    cout<<"Stack underflow"<<endl;

}