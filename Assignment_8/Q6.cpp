#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueue {
public:
    int heap[MAX], size;

    PriorityQueue() { size = 0; }

    void swap(int &a, int &b){
        int t = a; a = b; b = t;
    }

    void heapifyUp(int i){
        int p = (i - 1) / 2;
        if(i > 0 && heap[i] > heap[p]){
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < size && heap[l] > heap[largest]) largest = l;
        if(r < size && heap[r] > heap[largest]) largest = r;

        if(largest != i){
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(int x){
        heap[size] = x;
        heapifyUp(size);
        size++;
    }

    int getMax(){
        if(size == 0) return -1;
        return heap[0];
    }

    int extractMax(){
        if(size == 0) return -1;
        int mx = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapifyDown(0);
        return mx;
    }

    void display(){
        for(int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main(){
    PriorityQueue pq;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        pq.insert(x);
    }

    pq.display();
    cout << pq.getMax() << endl;
    cout << pq.extractMax() << endl;
    pq.display();
}