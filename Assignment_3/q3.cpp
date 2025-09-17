#include <iostream>
using namespace std;
#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = x;
    }

    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
        {
            return '\0';
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

bool isBalanced(char expr[])
{
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.empty();
}

int main()
{
    char expr[MAX];
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
