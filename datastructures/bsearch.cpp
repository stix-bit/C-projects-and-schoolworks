#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search (Iterative)
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found
        } 
        else if (arr[mid] < target) {
            left = mid + 1;  // Search in right half
        } 
        else {
            right = mid - 1; // Search in left half
        }
    }
    return -1;  // Target not found
}

int main() {
    int arr[] = {50, 20, 70, 10, 30, 60, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    // Sort the array first
    bubbleSort(arr, size);

    // Display the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the number to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
