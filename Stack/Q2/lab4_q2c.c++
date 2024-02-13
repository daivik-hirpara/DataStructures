#include<iostream>
#include<algorithm>
using namespace std;

void push(string value);
void display();
void pop();
string peek();
bool isempty();
bool isfull();

string stack[100];
int top = -1;


bool isoperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

string pretoin(string s)
{
    reverse(s.begin(),s.end());
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isoperand(s[i]))
        {
            string op(1, s[i]);
            push(op);
        }
        else
        {
            string op1 = peek();
            pop();
            string op2 = peek();
            pop();

            push("(" + op1 + s[i] + op2 + ")");
        }
    }

    return peek();
}

string pretopo(string s)
{
    reverse(s.begin(),s.end());
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isoperand(s[i]))
        {
            string op(1, s[i]);
            push(op);
        }
        else
        {
            string op1 = peek();
            pop();
            string op2 = peek();
            pop();

            push(op1+op2+s[i]);
        }
    }

    return peek();
}


int main()
{
    cout << "Enter the prefix expression: ";
    string prefix;
    cin >> prefix;
    string infix = pretoin(prefix);
    string postfix = pretopo(prefix);

    cout << "Prefix expression: " << prefix << endl;
    cout << "Infix expression: " << infix << endl; 
    cout << "Postfix expression: " << postfix << endl;

  

    return 0;
}

void push(string value)
{
    if (!isfull())
    {
        top = top + 1;
        stack[top] = value;
    }
}

void pop()
{
    if (!isempty())
    {
        top--;
    }
}

string peek()
{
    if (!isempty())
    {
        return stack[top];
    }
    return "";
}

bool isempty()
{
   return (top == -1);
}


bool isfull()
{
   return (top == 99);
}


