#include<iostream>
#include<algorithm>
using namespace std;

void push(int value);
void display();
void pop();
char peek();
bool isempty();
bool isfull();

char stack[100];
int n;
int top = -1;

int prec (char ch)
{
  
    if(ch == '^')
    return 3;
    else if(ch == '*' || ch == '/')
    return 2;
    else if (ch == '+' || ch == '-')
    return 1;
    else
    return -1;


}

bool isoperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


string intopo(string s)
{
     
    n = s.size();
    string result;

    for(int i=0;i<n;i++)
    {
        if(isoperand(s[i]))
        {
            result.push_back(s[i]);
        }

        else if(s[i] == '(')
        {
            push('(');
        }

        else if(s[i] == ')')
        {
           while(peek() != '(')
            {
              result.push_back(peek());
              pop();
            }
            pop();
        }

        else
        {
            while(!isempty()  && peek() != '(' && prec(peek())>=prec(s[i]))
            {
                result.push_back(peek());
                pop();
            }
            push(s[i]);
        }
    }

    while(!isempty())
    {
        result.push_back(peek());
        pop();
    }


    return result;

}


string intopre(string s)
{
    reverse(s.begin(),s.end());

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        s[i] = ')';
        else if(s[i]==')')
        s[i] = '(';
    }

    string result = intopo(s);
    reverse(result.begin(),result.end());
    return result;

}


int main()
{   
    cout<<"Enter the infix expression"<<endl;
    string infix;
    cin>>infix;
    string postfix = intopo(infix);
    string prefix  = intopre(infix);
    
    cout << "Infix expression: " << infix << endl; 
    cout << "Postfix expression: " << postfix << endl;
    cout << "Prefix expression: " << prefix << endl;

    
    return 0;
}


void push(int value)
{
    if(!isfull())
    {
        top = top + 1;
        stack[top]=value;
    }
}

void pop()
{
    if(!isempty())
    {
       top--;
    }
}

char peek()
{ 

     if(!isempty())
    {
      return stack[top];
    }
     return '\0';
}


bool isempty()
{
   return top == -1;
}


bool isfull()
{
   return top == n-1;
}


