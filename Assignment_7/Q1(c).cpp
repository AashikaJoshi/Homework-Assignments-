#include <iostream>
using namespace std;


void bubbleSort(int a[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        bool didSwap = false;

        for (int j = 0; j < size - pass - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap)
            break;
    }
}

void display(int a[], int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}

int main() {
    int arr[] = {12,8,2,9,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    display(arr, n);

    return 0;
}
