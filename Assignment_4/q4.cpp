#include <iostream>
using namespace std;

#define MAX 1000  

class Queue {
    char arr[MAX];
    int frontIdx, rearIdx;

public:
    Queue() {
        frontIdx = 0;
        rearIdx = -1;
    }

    void push(char x) {
        if (rearIdx < MAX - 1) {
            arr[++rearIdx] = x;
        }
    }

    void pop() {
        if (!empty()) {
            frontIdx++;
        }
    }

    char front() {
        if (!empty())
            return arr[frontIdx];
        return '\0';
    }

    bool empty() {
        return frontIdx > rearIdx;
    }
};

class FirstNonRepeating {
public:
    void findFirstNonRepeating(char str[]) {
        Queue q;
        int freq[256] = {0};  

        for (int i = 0; str[i] != '\0'; i++) {
            char ch = str[i];
            if (ch == ' ') continue; 

            freq[(int)ch]++;
            q.push(ch);

            while (!q.empty() && freq[(int)q.front()] > 1) {
                q.pop();
            }

            if (q.empty()) cout << "-1 ";
            else cout << q.front() << " ";
        }
        cout << endl;
    }
};

int main() {
    char input[] = "a a b c";
    FirstNonRepeating obj;
    obj.findFirstNonRepeating(input);
    return 0;
}