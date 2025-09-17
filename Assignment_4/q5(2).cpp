#include<iostream>
#include<queue>
using namespace std;

class Solution {
    public:
        queue<int> q1;

        void push(int x) {
            int size = q1.size();
            q1.push(x);
            for(int i=0; i<size; i++) {
                q1.push(q1.front());
                q1.pop();
            }
        }  
        
        void pop() {
            if(q1.empty()) {
                cout<<"Stack is EMPTY!!"<<endl;
                return;
            }
            cout<<"Popped element: "<<q1.front()<<endl;
            q1.pop();
        }
        int top() {
            if(q1.empty()) {
                cout<<"Stack is EMPTY!!"<<endl;
                return -1;
            }
            return q1.front();
        }
        bool empty() {
            return q1.empty();
        }
};

int main() {
    Solution s;

    cout << "=== Stack using 1 Queue ===" << endl;

    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    s.pop();
    s.pop();
    s.pop();

    s.pop();

    return 0;
}