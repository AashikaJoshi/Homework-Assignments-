#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapsortIncreasing(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n-1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapifyMin(int arr[], int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;
    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i){
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapifyMin(arr, n, smallest);
    }
}

void heapsortDecreasing(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for(int i = n-1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapifyMin(arr, i, 0);
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int arr[n], a1[n], a2[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        a1[i] = arr[i];
        a2[i] = arr[i];
    }

    heapsortIncreasing(a1, n);
    heapsortDecreasing(a2, n);

    cout << "Increasing order: ";
    print(a1, n);

    cout << "Decreasing order: ";
    print(a2, n);

    return 0;
}