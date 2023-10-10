#include <stdio.h>

// Function to perform Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to perform Binary Search (array must be sorted)
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Return the index where the key is found
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if key is not found
}

// Function to insert an element at a given position in the array
void insertElement(int arr[], int *n, int position, int value) {
    if (*n >= position) {
        for (int i = *n; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = value;
        (*n)++;
        printf("Element %d inserted at position %d.\n", value, position);
    } else {
        printf("Invalid position for insertion.\n");
    }
}

// Function to delete an element at a given position in the array
void deleteElement(int arr[], int *n, int position) {
    if (*n > 0 && position >= 0 && position < *n) {
        int deletedValue = arr[position];
        for (int i = position; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Element %d deleted from position %d.\n", deletedValue, position);
    } else {
        printf("Invalid position for deletion.\n");
    }
}

// Function to traverse and print the array
void traverseArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, choice, key, position, value;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Insertion\n");
        printf("4. Deletion\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int linearResult = linearSearch(arr, n, key);
                if (linearResult != -1) {
                    printf("Key %d found at index %d.\n", key, linearResult);
                } else {
                    printf("Key %d not found in the array.\n", key);
                }
                break;
            case 2:
                printf("Enter the key to search (array must be sorted): ");
                scanf("%d", &key);
                int binaryResult = binarySearch(arr, 0, n - 1, key);
                if (binaryResult != -1) {
                    printf("Key %d found at index %d.\n", key, binaryResult);
                } else {
                    printf("Key %d not found in the array.\n", key);
                }
                break;
            case 3:
                printf("Enter the position for insertion: ");
                scanf("%d", &position);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertElement(arr, &n, position, value);
                break;
            case 4:
                printf("Enter the position for deletion: ");
                scanf("%d", &position);
                deleteElement(arr, &n, position);
                break;
            case 5:
                traverseArray(arr, n);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
