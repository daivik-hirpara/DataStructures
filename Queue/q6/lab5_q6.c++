#include<iostream>
using namespace std;

int q1[100];
int q2[100];
int stack[100];

int f1=-1;
int f2=-1;
int r1=-1;
int r2=-1;
int top=-1;

void push(int n)
{
    top++;
    stack[top]=n;
}
int pop()
{
    int n=stack[top];
    top--;
    return n;
}
void enque1(int n)
{
    if(f1==-1 && r1==-1)
    {
        f1=0;
        r1=0;
        q1[r1]=n;
    }
    else 
    {
        r1++;
        q1[r1]=n;
    }
}
int deque1()
{
    int n=q1[f1];
    
    if(f1==r1)
    {
    f1=-1;
    r1=-1;
    }
    else
    f1++;
    return n;
}
void enque2(int n)
{
    if(f2==-1 && r2==-1)
    {
        f2=0;
        r2=0;
        q2[r2]=n;
    }
    else 
    {
        r2++;
        q2[r2]=n;
    }
}
void display()
{
    cout<<"The queue is "<<endl;
    for(int i=f1;i<=r1;i++){
       cout<<q1[i]<<" ";
    }
    cout<<endl;
}

int main()
{   
    int a;
    cout<<"Press 1: Enqueue"<<endl;
    cout<<"Press 2: Dequeue"<<endl;
    cout<<"Press 3: display"<<endl;
    cout<<"Press 4: Exit"<<endl;
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
                enque1(val);
                break;
            }
            case 2: deque1();
                break;
            case 3: display();
                break;
            case 4: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=4);
   

    int k;
    cout<<"Enter number of wrong entries "<<endl;
    cin>>k;
    int n=r1+1;
    for(int i=1;i<=k;i++)
    {
        push(deque1());
    }
    for(int i=1;i<=k;i++)
    {
        enque2(pop());
    }
    for(int i=0;i<n-k;i++)
    {
        enque2(deque1());
    }
    
    cout<<"The queue is "<<endl;
    for(int i=0;i<n;i++){
       cout<<q2[i]<<" ";
    }
    cout<<endl;
 return 0;

}

