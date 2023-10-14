#include <stdio.h>


int maxMinArray(int arr[], int arraySize); // Function prototype

int main() {
    int arr[] = {3, 5, 8, 6, 2, 7, 10, 11};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    maxMinArray(arr, arraySize);

    return 0;
}


int maxMinArray(int arr[], int arraySize) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < arraySize; ++i) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    printf("Smallest elem: %d\n and biggest elem: %d\n", min, max);

    return min;
}