#include <iostream>
#include <vector>
using namespace std;

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    // Find the maximum and minimum elements in the array
    int maxElement = arr[0];
    int minElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement)
            maxElement = arr[i];
        if (arr[i] < minElement)
            minElement = arr[i];
    }

    int range = maxElement - minElement + 1;

    // Create the count array to store the frequency of each element
    vector<int> count(range, 0);

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - minElement]++;
    }

    // Modify the count array to store the cumulative frequency
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted order
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Counting Sort
    countingSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
