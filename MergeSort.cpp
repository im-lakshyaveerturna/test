#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1];
    int rightArray[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Merge the two sorted arrays
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from leftArray
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements from rightArray
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {38, 12, 27, 43, 9, 31, 18, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, n - 1);

    cout << "\n\nSorted array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}