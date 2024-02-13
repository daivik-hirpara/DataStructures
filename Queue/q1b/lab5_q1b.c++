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

class queue
{
    Node* f;
    Node* r;

    public:

    queue()
    {
        f=NULL;
        r=NULL;
    }

    int count =1;


    void enque(int val)
    {
        Node* new_node = new Node(val);

        if(f == NULL && r==NULL)
        {
            f = new_node;
            r = new_node;
        }

        else
        {
            r->next = new_node;
            r = new_node;
        }
        cout<<"Node is inserted"<<endl;
    }

    void deque()
    {
        if(f == NULL)
        {
            cout<<"Underflow"<<endl;
            return;
        }

        else
        {
            int v = f->val;
            cout<<"Deleted value is "<<v<<endl;

            Node* temp = f;
            f = f->next;

            if(f==NULL)
            r=NULL;
            free(temp);


        }
    }

    void isempty()
    {
        if(f == NULL)
        {
            cout<<"Queue is Empty"<<endl;
        } 
       else
       cout<<"Queue is Not Empty"<<endl;
    }
};

int main()
{   
    queue q;
    
    int a;
    cout<<"Press 1: Enqueue"<<endl;
    cout<<"Press 2: Dequeue"<<endl;
    cout<<"Press 3: isEmpty"<<endl;
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
                q.enque(val);
                break;
            }
            case 2: q.deque();
                break;
            case 3: q.isempty();
                break;
            case 4: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } 
    while(a!=4);
    return 0;
}
