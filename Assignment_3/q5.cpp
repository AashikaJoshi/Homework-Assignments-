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

int evaluatePostfix(char postfix[])
{
    Stack s;
    int i = 0;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            }
        }
        i++;
    }
    return s.pop();
}

int main()
{
    char postfix[MAX];
    cout << "Enter Postfix Expression (use single-digit numbers): ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix);
    return 0;
}
