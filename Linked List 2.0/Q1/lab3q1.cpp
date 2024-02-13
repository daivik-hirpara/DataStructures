#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* prev;
    Node* next;


    Node(int data)
    {
        val = data;
        prev =NULL;
        next = NULL;
    }
};

class DoublyLinkedlist
{
    public:
    Node* head;
    Node* tail;
    
    DoublyLinkedlist()
    {
        head=NULL;
        tail=NULL;
    }


    void display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp = temp -> next;
        }
        cout<<endl;

    }
    void insertAtend(int val)
   {
      Node* new_node = new Node(val);
      if(tail==NULL)
      {
        head = new_node;
        tail = new_node;
      }
      tail->next = new_node;
      new_node->prev = tail;
      tail = new_node;

   }
};  


class CircularLinkedList
{
    public:
    Node* head;
    
    CircularLinkedList()
    {
       head = NULL;
    }
    

    void display()
    {
        Node* temp = head;
        do
        {
           cout<<temp->val<<"->";
           temp = temp->next;
        } while (temp != head);
        cout<<endl;
        
    }

    void printcir()
    {
        Node* temp = head;
        for(int i=0;i<20;i++)
        {
           cout<<temp->val<<"->";
           temp = temp->next;
        }cout<<endl;
    }

     void insertAtend(int val)
    {
        Node* new_node = new Node(val);
        if(head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        Node* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = new_node;
        new_node->next = head;


    }
};

class DoublyCircularLinkedlist
{
    public:
    Node* head;
    Node* tail;
    
    DoublyCircularLinkedlist()
    {
        head=NULL;
        tail=NULL;
    }


    void display()
    {
        if(tail==NULL)
        {
        return;
        }
        Node* temp = head;
        do
        {
           cout<<temp->val<<" ";
           temp = temp->next;
        } while (temp != head);
        cout<<endl;

    }

     void printcir()
    {
        Node* temp = tail;
        for(int i=0;i<20;i++)
        {
           cout<<temp->val<<" ";
           temp = temp->prev;
        }cout<<endl;
    }

    void insertAtend(int val)
   {
      Node* new_node = new Node(val);
      if(tail==NULL)
      {
        head = new_node;
        tail = new_node;
        new_node->next = tail;
        new_node->prev=head;

      }
      new_node->next = tail->next;
      tail->next->prev = new_node;
      tail->next = new_node;
      new_node->prev = tail;
      tail = new_node;

   }
};     




void doublyll(int n)
{  
    DoublyLinkedlist dll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       dll.insertAtend(v);
    }
    dll.display();
}

void circularll(int n)
{
    CircularLinkedList cll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       cll.insertAtend(v);
    }
    cll.display();
    cout<<"For looping"<<endl;
    cll.printcir();

}

void cirdoublyll(int n)
{
    DoublyCircularLinkedlist dcll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       dcll.insertAtend(v);
    }
    dcll.display();
    cout<<"For looping"<<endl;
    dcll.printcir();

}

int main()
{
    int n;
    cout<<"Enter the size of an Linkedlist : "<<endl;
    cin>>n;


    cout<<endl;
    cout<<"Press : 1 To Create Doubly linked list."<<endl;
    cout<<"Press : 2 To Create Circular linked list. " <<endl;
    cout<<"Press : 3 To Create Doubly Circular linked list. "<<endl;

  

    int select;
    cout<<"Enter your choice : "<<endl;
    cin>>select;

switch (select){
    case 1: doublyll(n);
            break;
    case 2: circularll(n);
            break;
    case 3: cirdoublyll(n);
            break;
    default: cout<<"Kindky choose the valid number first."<<endl;
}
    
    return 0;
}