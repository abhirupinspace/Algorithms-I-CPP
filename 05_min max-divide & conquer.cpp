#include <iostream>
using namespace std;

// Structure to store the minimum and maximum
struct MinMax {
    int min;
    int max;
};

// Recursive function to find min and max
MinMax findMinMax(int arr[], int left, int right) {
    MinMax result, leftResult, rightResult;
    
    // If there is only one element
    if (left == right) {
        result.min = arr[left];
        result.max = arr[left];
        return result;
    }

    // If there are two elements
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            result.min = arr[left];
            result.max = arr[right];
        } else {
            result.min = arr[right];
            result.max = arr[left];
        }
        return result;
    }

    // Divide the array into two halves
    int mid = (left + right) / 2;
    leftResult = findMinMax(arr, left, mid);
    rightResult = findMinMax(arr, mid + 1, right);

    // Combine the results
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int main() {
    int size;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Finding minimum and maximum using divide and conquer
    MinMax result = findMinMax(arr, 0, size - 1);

    cout << "Minimum element: " << result.min << endl;
    cout << "Maximum element: " << result.max << endl;

    return 0;
}
