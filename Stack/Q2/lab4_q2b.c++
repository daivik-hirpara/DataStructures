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

string potoin(string s)
{
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

            push("(" + op2 + s[i] + op1 + ")");
        }
    }

    return peek();
}

string potopre(string s)
{
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

            push(s[i]+op2+op1);
        }
    }

    return peek();
}


int main()
{
    cout << "Enter the postfix expression: ";
    string postfix;
    cin >> postfix;
    string infix = potoin(postfix);
    string prefix = potopre(postfix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Infix expression: " << infix << endl; 
    cout << "Prefix expression: " << prefix << endl;

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


