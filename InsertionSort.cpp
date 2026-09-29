#include<iostream>
#include<ctime>

using namespace std;

void insertionSort(int arr[], int n, int &comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
    
}

int main() {
    srand(time(0));
    
    for (int size = 30; size <= 1000; size += 10) {
        int totalComparisons = 0;

        for (int instance = 0; instance < 10; instance++) {
            int arr[size];

            // Fill array with random values
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 1000;
            }

            int comparisons = 0;
           // clock_t start = clock();
   
    
            // Perform Insertion Sort and count comparisons
            insertionSort(arr, size, comparisons);
            //clock_t end = clock();
            
           // double z=(end - start) / CLOCKS_PER_SEC;
            totalComparisons += comparisons;
        }

        // Calculate and print the average number of comparisons
        double averageComparisons = static_cast<double>(totalComparisons) / 10.0;
       // cout << "Array size: " << size << ", Average Comparisons: " << averageComparisons << endl;
       cout << size << " " << averageComparisons << endl;
    }

    return 0;
}
