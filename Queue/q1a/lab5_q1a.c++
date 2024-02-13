#include<iostream>
using namespace std;


int arr[100];
int f = -1;
int r = -1;
int n;
void enque(int val)
{
    if((f==0 && r==n-1)||(f==r+1))
    {
        cout<<"Overflow"<<endl;
        return;
    }

    else
    {
        if(f == -1 && r==-1)
        {
            f=0;
            r=0;
        }
        else
        r++;

        arr[r] = val;
        cout<<"Element is inserted"<<endl;
    }
}

void deque()
{
    if(f==-1 || f>r)
    {
        cout<<"Underflow"<<endl;
        return;
    }

    else
    {
         int v = arr[f];
         cout<<"Deleted value is "<<v<<endl;

         if(f==r)
         {
            f=-1;
            r=-1;
         }
         else
         f++;
    }
}

void isempty()
{
    if(f==-1)
    cout<<"Queue is Empty"<<endl;

    else
    cout<<"Queue is Not Empty"<<endl;

}

void isfull()
{
    if(f==0 && r==n-1)
    cout<<"Queue is Full"<<endl;

    else
    cout<<"Queue is Not Full"<<endl;

}


int main()
{   
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    int a;
    cout<<"Press 1: Enqueue"<<endl;
    cout<<"Press 2: Dequeue"<<endl;
    cout<<"Press 3: isEmpty"<<endl;
    cout<<"Press 4: isFull"<<endl;
    cout<<"Press 5: Exit"<<endl;
   
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
            case 2: deque();
                break;
            case 3: isempty();
                break;
            case 4: isfull();
                break;
            case 5: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=5);
    return 0;
}
