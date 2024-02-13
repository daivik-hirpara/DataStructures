#include<iostream>
using namespace std;

int stack1[100];
int stack2[100];
int n;
int top1 = -1;
int top2 = -1;
void push1(int value)
{
        top1 = top1 + 1;
        stack1[top1]=value; 
}
int  pop1()
{
    int x =stack1[top1--];
    return x;
}
void push2(int value)
{
    top2 = top2 + 1;
    stack2[top2]=value; 
}
int  pop2()
{
    int x =stack2[top2--];
    return x;
}
void enque(int val)
{
    push1(val);
}
void deque()
{
    int n;
    int t1=top1;
    if(top1==-1)
    cout<<"queue is empty"<<endl;

    else
    {
        for(int i=0;i<t1;i++)
        {
            n=pop1();
            push2(n);
        }
        n=pop1();
        cout<<"Deleted element is "<<n<<endl;
        int t2=top2;
        for(int i=0;i<=top2;i++)
        {
            n=pop2();
            push1(n);
        }
    }
}

void display()
{
    cout<<"Queue is "<<endl;
    for(int i=0;i<=top1;i++)
    {
        cout<<stack1[i]<<" ";
    }
    cout<<endl;
}

int main()
{   
    int a;
    cout<<"Press 1: Enqueue"<<endl;
    cout<<"Press 2: Dequeue"<<endl;
    cout<<"Press 3: Display"<<endl;
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
                enque(val);
                break;
            }
            case 2: 
                 deque();
                break;
            case 3: display();
                break;
            case 4: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=4);
    return 0;
}
