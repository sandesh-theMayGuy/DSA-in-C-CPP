#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0};
    // Count occurrences of each digit in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    // Change count[i] so that count[i] now contains
    // the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to implement Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit. Note that
    // instead of passing the digit number, exp is passed.
    // exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);
    radixSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
