#include<iostream>
using namespace std;

int i=-1;
int n;
int q[100];
int priority[100];

bool isempty()
{
    return(i==-1);
}
bool isfull()
{
    return(i==99);
}
void enque(int val,int pri)
{

    if(!isfull())
    {
        if(i == -1)
        {
            i++;
            q[i]=val;
            priority[i]=pri;
            return;
        }
        else
        {
            i++;
            for(int j=i-1;j>=0;j--)
            {
                if(priority[j]>=pri)
                {
                    q[j+1]=q[j];
                    priority[j+1]=priority[j];
                }
                else
                {
                    q[j+1]=val;
                    priority[j+1]=pri;
                    break;
                }
            }
        }
    }
}

void deque()
{
    if(isempty())
    cout<<"Underflow"<<endl;
    else
    {
      int x = q[i--];
      cout<<"deleted element is "<<x<<endl;
    }
}

void display()
{
    for(int j=0;j<=i;j++)
    {
        cout<<q[j]<<priority[j]<<endl;
    }
}

int main()
{   
  
    int a;
    cout<<"Press 1: Enqueue"<<endl;
    cout<<"Press 2: deque"<<endl;
    cout<<"Press 3: isEmpty"<<endl;
    cout<<"Press 4: isFull"<<endl;
    cout<<"Press 5: display"<<endl;
    cout<<"Press 6: Exit"<<endl;
   
    do {
        
        cout<<"Enter your choice : "<<endl;
        cin>>a;
        switch (a) 
        {
        
            case 1:
            {
                cout<<"enter element and priority:"<<endl;
                int v,p;
                cin>>v>>p;
                enque(v,p);
                break;
            }
            case 2: deque();
                break;
            case 3: 
            {
                if(isempty())
                cout<<"queue is empty"<<endl;
                else
                cout<<"queue is Not empty"<<endl;
                break;
            }
            case 4: 
            {
                if(isfull())
                cout<<"queue is full"<<endl;
                else
                cout<<"queue is Not full"<<endl;
                break;
            }
            case 5:
            display();
            break;

            case 6: cout<<"Exit"<<endl;
            break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=6);

    return 0;
}

