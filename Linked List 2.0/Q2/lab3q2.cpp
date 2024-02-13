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
    void displayrev()
    {
        
        Node* temp = head;
        while(temp->next !=NULL)
        {
           
            temp = temp -> next;
        }

        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->prev;

        }
    }

    
    void insertAtbeg(int val)
    {
        Node* new_node = new Node(val);
        if(head == NULL)
        {
            head = new_node;
            head->prev = NULL;
            
            tail = new_node;
            return;
        }

        new_node->next=head;
        head->prev = new_node;
        head = new_node;
        return;

   }
   
    void insertAtend(int val)
   {
      
      if(head==NULL)
      {
        Node* newone = new Node(val);
        head = newone;
        tail = newone;
      }
      else
      {
        Node* new_node = new Node(val);
      
      tail->next = new_node;
      new_node->prev = tail;
      tail = new_node;
      }
   }

   void insertAtpos(int val, int pos)
   {
     Node* new_node = new Node(val);
     int count = 0;
     if(pos == 0)
     {
        insertAtbeg(val);
        return;
     }
     Node* temp = head;
     while(count < pos-1)
     {
        temp = temp->next;
        count++;

     }
     if(temp->next == NULL)
     {
        insertAtend(val);
        return;
     }

     new_node->next = temp->next;
     temp->next->prev = new_node;
     temp->next = new_node;
     new_node->prev = temp;
     return; 

     
   }

   void deleteAtbeg()
   {
       if(head == NULL)
       {
        return;
       }
       Node* temp = head;
       head = head->next;
       if(head == NULL)
       {
        tail = NULL;
       }
       else
       {
       head->prev = NULL;
      
       }
    free(temp);

   }


   void deleteAtend()
   {
      if(head == NULL)
       { 
        return;
       }
      Node* temp = tail;
      tail = tail->prev;
      if(tail == NULL)
       {
        head = NULL;
       }
       else
       {
          tail->next = NULL;
      
       }
       free(temp);

   }

   void deleteAtpos(int k)
   {
     Node* temp =head;
     int count=0;
     if(k==0)
     {
        deleteAtbeg();
        return;
     }
     while(count<k)
     {
        temp = temp->next;
        count++;

     }
     if(temp->next == NULL)
     {
        deleteAtend();
        return;
     }
    temp->prev->next= temp->next;
    temp->next->prev = temp->prev;
    free(temp);

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
    
     void insertAtbeg(int val)
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
        head = new_node;

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


      void insertAtpos(int val,int k)
    {
        if(k==0)
        {
            insertAtbeg(val);
            return;
        }
        Node* new_node = new Node(val);
        Node* temp = head;
        int count =0;
        while(count != k-1)
        {
            temp = temp->next;
            count++;
        }
        
        if(temp->next  == head )
        {
            insertAtend(val);
            return;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void deleteAtbeg()
    {
        if(head == NULL)
        {
            return;
        }

        Node* temp = head;
        Node* tail = head;
        while(tail->next != head)
        {
            tail = tail->next;
        }
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
        }
        else
        tail->next = head;
        free(temp);


    }


    void deleteAtend()
    {
        if(head == NULL)
        {
            return;
        }
        Node* tail = head;

        while(tail->next->next != head)
        {
            tail = tail->next;
        }
        Node* temp = tail->next;
        tail->next = head;
        free(temp);
        
    }

    void deleteAtpos(int k)
    {
        if(k==0)
        {
            deleteAtbeg();
            return;
        }

        Node* temp = head;
        int c=0;
        while(c!=(k-1))
        {
            temp = temp->next;
            c++;
        }

        if(temp->next ==head)
        {
            deleteAtend();
            return;
        }

        Node* temp1 = temp->next;
        temp->next = temp->next->next;
        free(temp1);
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
    
    
    void insertAtbeg(int val)
    {
        Node* new_node = new Node(val);
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
            new_node->next = head;
            new_node->prev=tail;
            return;
        }

        new_node->next=head;
        head->prev = new_node;
        tail->next = new_node;
        new_node->prev = tail;
        head = new_node;
        return;

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

   void insertAtpos(int val, int pos)
   {
        if(pos==0)
        {
            insertAtbeg(val);
            return;
        }
     Node* new_node = new Node(val);
     int count = 0;
     Node* temp = head;
     while(count < pos-1)
     {
        temp = temp->next;
        count++;

     }
      if(temp->next  == head )
        {
            insertAtend(val);
            return;
        }

     new_node->next = temp->next;
     temp->next->prev = new_node;
     temp->next = new_node;
     new_node->prev = temp;
     return; 

     
   }

   void deleteAtbeg()
   {
       if(head == NULL)
       {
        return;
       }


       Node* temp = head;
       head = head->next;
       if(head == NULL)
       {
        tail = NULL;
       }
       else
       {
       tail->next = head;
       head->prev = tail;
       }
      
    free(temp);

   }


   void deleteAtend()
   {
      if(head == NULL)
       { 
        return;
       }
      Node* temp = tail;
      tail = tail->prev;
      if(tail == NULL)
       {
        head = NULL;
       }
       else
       {
          tail->next = head;
          head->prev = tail;
      
       }
       free(temp);

   }

   void deleteAtpos(int k)
   {

     if(k==0)
    {
            deleteAtbeg();
            return;
    }
     Node* temp =head;
     int count=0;
     while(count<k)
     {
        temp = temp->next;
        count++;

     }
     if(temp->next ==head)
        {
            deleteAtend();
            return;
        }

    temp->prev->next= temp->next;
    temp->next->prev = temp->prev;
    free(temp);

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
    cout<<"Traversing From begning"<<endl;
    dll.display();
    cout<<"Traversing From End"<<endl;
    dll.displayrev();
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
    cout<<"Traversing From begning"<<endl;
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
    cout<<"Traversing From begning"<<endl;
    dcll.display();
    cout<<"Traversing From End and looping"<<endl;
    dcll.printcir();

}

void insertdoublyll(int n)
{
    DoublyLinkedlist dll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       dll.insertAtend(v);
    }
    cout<<"Traversing From begning"<<endl;
    dll.display();

    cout<< "Enter the element and postion respectively"<<endl;
    int e,p;
    cin>>e;
    cin>>p;
    dll.insertAtpos(e,p);
    dll.display();
    
}


void insertcircularll(int n)
{
    CircularLinkedList cll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       cll.insertAtend(v);
    }
    cout<<"Traversing From begning"<<endl;
    cll.display();

    cout<< "Enter the element and postion respectively"<<endl;
    int e,p;
    cin>>e;
    cin>>p;
    cll.insertAtpos(e,p);
    cll.display();
    cll.printcir();
}

void insertcirdoublyll(int n)
{
    DoublyCircularLinkedlist dcll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       dcll.insertAtend(v);
    }
    cout<<"Traversing From begning"<<endl;
    dcll.display();

    cout<< "Enter the element and postion respectively"<<endl;
    int e,p;
    cin>>e;
    cin>>p;
    dcll.insertAtpos(e,p);
    dcll.display();
    dcll.printcir();

}


void deletedoublyll(int n)
{
    DoublyLinkedlist dll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       dll.insertAtend(v);
    }
    cout<<"Traversing From begning"<<endl;
    dll.display();
    int p;
    cout<< "Enter the  postion to be deleted"<<endl;
    cin>>p;
    dll.deleteAtpos(p);
    dll.display();

}

void deletecircularll(int n)
{
    CircularLinkedList cll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       cll.insertAtend(v);
    }
    cout<<"Traversing From begning"<<endl;
    cll.display();

    cout<< "Enter the  postion to be deleted"<<endl;
    int p;
    
    cin>>p;
    cll.deleteAtpos(p);
    cll.display();
    cll.printcir();

}

void deletecirdoublyll(int n)
{
    DoublyCircularLinkedlist dcll;
    cout<<"Enter Elements"<<endl;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
       dcll.insertAtend(v);
    }
    cout<<"Traversing From begning"<<endl;
    dcll.display();

    cout<< "Enter the postion to be deleted"<<endl;
    int p;
    
    cin>>p;
    dcll.deleteAtpos(p);
    dcll.display();
    dcll.printcir();
}



int main()
{
    int n;
    cout<<"Enter the size of an Linkedlist : "<<endl;
    cin>>n;


    cout<<endl;
    cout<<"Press : 1 To Traverse Doubly linked list."<<endl;
    cout<<"Press : 2 To Traverse Circular linked list. " <<endl;
    cout<<"Press : 3 To Traverse Doubly Circular linked list. "<<endl;
    cout<<"Press : 4 To Insert ELement in  Doubly linked list. "<<endl;
    cout<<"Press : 5 To Insert ELement in  Circular linked list. "<<endl;
    cout<<"Press : 6 To Insert ELement in  Doubly Circular linked list. "<<endl;
    cout<<"Press : 7 To Delete ELement in  Doubly linked list. "<<endl;
    cout<<"Press : 8 To Delete ELement in  Circular linked list. "<<endl;
    cout<<"Press : 9 To Delete ELement in  Doubly Circular linked list. "<<endl;
    


  

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
    case 4: insertdoublyll(n);
            break;
    case 5: insertcircularll(n);
            break;
    case 6: insertcirdoublyll(n);
            break;
    case 7: deletedoublyll(n);
            break;
    case 8: deletecircularll(n);
            break;
    case 9: deletecirdoublyll(n);
            break;
    
    
    default: cout<<"Kindky choose the valid number first."<<endl;
}
    
    return 0;
}