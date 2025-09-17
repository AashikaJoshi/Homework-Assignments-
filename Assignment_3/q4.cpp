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

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
bool isOperand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    int i = 0, k = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isOperand(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.peek() != '(')
            {
                postfix[k++] = s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.peek()) >= precedence(ch))
            {
                postfix[k++] = s.pop();
            }
            s.push(ch);
        }
        i++;
    }

    while (!s.empty())
    {
        postfix[k++] = s.pop();
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];
    cout << "Enter Infix Expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix Expression: " << postfix;
    return 0;
}
