#include <iostream>
using namespace std;

void dualSelectionSort(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        int smallest = left;
        int largest = right;

        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[smallest])
                smallest = i;
            if (arr[i] > arr[largest])
                largest = i;
        }

        swap(arr[left], arr[smallest]);

        if (largest == left)
            largest = smallest;

       
        swap(arr[right], arr[largest]);

        left++;
        right--;
    }
}

int main() {
    int arr[] = {12, 4, 9, 1, 6, 15, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    dualSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
