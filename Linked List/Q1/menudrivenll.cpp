#include<iostream>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;

    Node(int data)
    {
        val=data;
        next=NULL;
    }
};


class Linkedlist
{
   public:
   Node* head;

   Linkedlist()
   {
     head=NULL;
   }
   
   void insertAtTail(int value)
   {
           Node* new_node =new Node(value);
           if(head==NULL)
           { 
              head = new_node;
              return; 
           }

           Node* temp = head;
           while(temp->next != NULL)
           {
               temp = temp->next;
           }

           temp->next = new_node;
   }


   
    void insertAtHead(int val)
   {
     Node* new_node = new Node(val);
     new_node->next = head;
     head = new_node; 
   }


   void deleteAttail()
{
   Node* second_last = head;
   while(second_last->next->next != NULL)
   {
       second_last= second_last->next;
   }

   Node* temp = second_last->next;
   second_last->next = NULL;
   free(temp);

}

  void count()
  {
    int c=0;
    Node* temp = head;
    while(temp!=NULL)
    {
      c++;
      temp = temp ->next;
    } 
    cout<<"Number of nodes in above linked list is : "<<c<<endl;
  }

  Node* reverse()
{
    Node* prevptr = NULL;
    Node* currptr = head;

    while (currptr!=NULL)
    {
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr =currptr;
        currptr = nextptr;

    }
    Node* new_head  = prevptr;
    return new_head;
    

}
  
  bool detectcycle()
  {
    if(!head)
    {
        return false;
    }
     Node* slow =head;
     Node* fast =head;

     while(fast && fast->next)
     {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
        {
            return true;
        }
     }
     
     return false;
 }


   void display()
   {
      Node* temp = head;
      while(temp!=NULL)
      {
        cout<<temp->val<<"->";
        temp = temp->next;
      }
      cout<<"NULL"<<endl;
   }



};




void createList(int n)
{
    Linkedlist ll;
    int v;
    cout<<"Enter the linked list elements"<<endl;
    for(int i=1;i<=n;i++)
    { 
        cin>>v;
         ll.insertAtTail(v);

    }
  
    ll.display();
}


void insertAtbeg(int n)
{   
    
    Linkedlist ll;
    int v;
    cout<<"Enter the linked list elements"<<endl;
    for(int i=1;i<=n;i++)
    { 
        cin>>v;
         ll.insertAtTail(v);

    }
  
    ll.display();
    int c;
    cout<<"Enter the element which is inserted at head"<<endl;
    cin>>c;

    ll.insertAtHead(c);
    ll.display();

}


void del(int n)
{
    Linkedlist ll;
    int v;
    cout<<"Enter the linked list elements"<<endl;
    for(int i=1;i<=n;i++)
    { 
        cin>>v;
         ll.insertAtTail(v);

    }
  
    ll.display();
    cout<<"Linked list after deleting last element"<<endl;

    ll.deleteAttail();
    ll.display();

}

void counting(int n)
{

    
    Linkedlist ll;
    int v;
    cout<<"Enter the linked list elements"<<endl;
    for(int i=1;i<=n;i++)
    { 
        cin>>v;
         ll.insertAtTail(v);

    }
  
    ll.display();

    ll.count();


}

void rev(int n)
{
     
    Linkedlist ll;
    int v;
    cout<<"Enter the linked list elements"<<endl;
    for(int i=1;i<=n;i++)
    { 
        cin>>v;
         ll.insertAtTail(v);

    }
  
    ll.display();

    cout<<"Reversed linked list"<<endl;
    ll.head=ll.reverse();
    ll.display();
}

void cycle(int n)
{
      
    Linkedlist ll;
    int v;
    cout<<"Enter the linked list elements"<<endl;
    for(int i=1;i<=n;i++)
    { 
        cin>>v;
         ll.insertAtTail(v);

    }
  
    ll.display();
    cout<<"no loop found"<<endl;
    cout<<ll.detectcycle();

    cout<<endl;
    Node* temp = ll.head;
    while(temp->next!=NULL)
    temp = temp->next;
  
    temp->next = ll.head->next->next;
    cout<<"After looping"<<endl;
    cout<<"Loop Detected"<<endl;
    cout<<ll.detectcycle();
    ll.detectcycle();

}


int main()
{
    int n;
    cout<<"Enter the size of an Linkedlist : "<<endl;
    cin>>n;


    cout<<endl;
    cout<<"Press : 1 To Create The list"<<endl;
    cout<<"Press : 2 To Insert the element at the beginning of the linked list." <<endl;
    cout<<"Press : 3 To Delete the Last element of the linked list. "<<endl;
    cout<<"Press : 4 To Count the number of elements in a linked list."<<endl;
    cout<<"Press : 5 To Reverse the linked list."<<endl;
    cout<<"Press : 6 To Find loop in the linked list."<<endl;
    cout<<"Press : 7 To Exit"<<endl;

    int select;
    cout<<"Enter your choice : "<<endl;
    cin>>select;

switch (select){
    case 1: createList(n);
            break;
    case 2: insertAtbeg(n);
            break;
    case 3: del(n);
            break;
    case 4: counting(n);
            break;
    case 5: rev(n);
            break;
    case 6: cycle(n);
            break;

    default: cout<<"Kindky choose the valid number first."<<endl;
}
    
    return 0;
}
