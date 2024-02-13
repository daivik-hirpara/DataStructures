#include<iostream>
using namespace std;

int arr[100];
int f = -1;
int r = -1;

void enque(int val)
{
        if(f == -1 && r==-1)
        {
            f=0;
            r=0;
        }
        else
        r++;
        arr[r] = val; 

}
void deque()
{
        if(f==r)
         {
            f=-1;
            r=-1;
         }
         else
         f++;
}
int front()
{
    if(f==-1 || f>r)
    {   
        return -1;
    }
    else
    {
        int v = arr[f];
        return v;
    }
}
bool isempty()
{
    return (f==-1);
}


void push(int val)
{   
    enque(val);
    while(front()!=val)
    {
        enque(front());
        deque();
       
    }
    
}

void pop()
{
    if(isempty())
    cout<<"Stack underflow"<<endl;
    else
    {
        int v = front();
        cout<<"Popped element is "<<v<<endl;
        deque();
        
    }
}

int top()
{
    if(isempty())
    cout<<"Stack underflow"<<endl;
    else
    return front();
}

int main()
{
    int choice, value;
   
    
    cout<<"Implementation of Stack using Queue"<<endl;
    

    while (1) 
    {
        cout<<endl;
        cout<<"Press : 1 To Push"<<endl;
        cout<<"Press : 2 To Pop" <<endl;
        cout<<"Press : 3 To find peek "<<endl;
        cout<<"Press : 4 To find is empty"<<endl;
        cout<<"Press : 5 To Exit"<<endl;


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
            {
                int v = top();
                cout<<"topmost value is "<<v<<endl;
                break;
            }     
        case 4:
            {
            if(isempty())
            cout<<"Stack is Empty"<<endl;
            else
            cout<<"Stack is Not Empty"<<endl;
            break;
            }
        case 5:
            exit(0);
            break;
        default:
            cout<<"Wrong choice entered"<<endl;
           
        }
    }

    

    return 0;
}
