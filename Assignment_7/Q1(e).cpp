#include <iostream>
using namespace std;

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];     
    int smallerIndex = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[++smallerIndex], arr[j]);
        }
    }

    swap(arr[smallerIndex + 1], arr[high]);
    return smallerIndex + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivotIndex = partitionArray(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main() {
    int arr[] = {45, 12, 78, 23, 56, 9, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
