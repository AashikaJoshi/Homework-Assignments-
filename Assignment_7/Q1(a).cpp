#include <iostream>
using namespace std;

int main()
{
    int arr[] = {9,2,6,5,11};
    int n = sizeof(arr) / sizeof(int);
    int i = 0;
    while (i != n-1)
    {
      int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}