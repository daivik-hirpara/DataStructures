#include<iostream>
using namespace std;

int d[100];
int f=-1;
int r=-1;
int n;

bool isempty()
{
    return(f==-1);
}
bool isfull()
{
    return((f==0 && r==n-1)||(f!=0 && r==(f-1)%(n-1))||f==r+1);
}

void pushfront(int val)
{
    if(isfull())
    {
        cout<<"overflow"<<endl;
        return ;
    }
    else if (isempty())
    {
        f=0;
        r=0;
    }
    else if(f==0 && r!=n-1) 
    {
        f=n-1;
    } 
    else
    {
        f--;
    }
    d[f] = val;
}

void pushback(int val)
{
    if(isfull()) 
    {
    cout<<"overflow"<<endl;
    return ;
    }
    else if(isempty()) 
    {
        f=0;
        r=0;
    }
    else if(r==n-1 && f!=0) 
    {
        r=0;
    } 
    else
    {
        r++;
    }
    d[r] = val;
}

void popfront()
{
    if(isempty())
    {   
     cout<<"Underflow"<<endl;
     return ;
    }
        
    int ans = d[f];    
    if(f==r) 
    { 
        f=-1;
        r=-1;
    }
    else if(f==n-1) 
    {
        f=0; 
    }
    else
    {
        f++;
    }
    cout<<"Deleted element from front is "<<ans<<endl;
}

void popback()
{
    if(isempty())
    {
    cout<<"Underflow"<<endl;
     return ;
    }
        
    int ans = d[r];
    
    if(f==r) 
    { 
        f=-1;
        r=-1;
    }
    else if(r == 0) 
    {
        r=n-1; 
    }
    else
    {
        r--;
    }
    cout<<"Deleted element from back is "<<ans<<endl;
}

int main()
{   
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    int a;
    cout<<"Press 1: pushfront"<<endl;
    cout<<"Press 2: pushback"<<endl;
    cout<<"Press 3: popfront"<<endl;
    cout<<"Press 4: popback"<<endl;
    cout<<"Press 5: isEmpty"<<endl;
    cout<<"Press 6: isFull"<<endl;
    cout<<"Press 7: Exit"<<endl;
   
    do {
        
        cout<<"Enter your choice : "<<endl;
        cin>>a;
        switch (a) 
        {
        
            case 1:
            {
                cout<<"enter element:"<<endl;
                int val;
                cin>>val;
                pushfront(val);
                break;
            }
            case 2:
            {
                cout<<"enter element:"<<endl;
                int val;
                cin>>val;
                pushback(val);
                break;
            }
            case 3: popfront();
                break;
            case 4: popback();
                break;
            case 5: 
            {
                if(isempty())
                cout<<"Deque is empty"<<endl;
                else
                cout<<"Deque is Not empty"<<endl;
                break;
            }
            case 6: 
            {
                if(isfull())
                cout<<"Deque is full"<<endl;
                else
                cout<<"Deque is Not full"<<endl;
                break;
            }
            case 7: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=7);
    return 0;
}
