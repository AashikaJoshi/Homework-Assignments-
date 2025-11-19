#include <iostream>
using namespace std;


void insertionSort(int a[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = a[i];
        int prev = i - 1;

  
        while (prev >= 0 && a[prev] > temp) {
            a[prev + 1] = a[prev];
            prev--;
        }

        a[prev + 1] = temp;
    }
}
void printArray(int a[], int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}

int main() {
    int arr[] = {10,7, 1, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
