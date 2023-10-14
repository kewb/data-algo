#include <stdio.h>
#include <limits.h> // Include limits.h for INT_MIN

void findThreeLargest(int arr[], int size, int result[]);
void findThreeSmallestEven(int arr[], int size, int result[]);
void avgSum(int arr[], int size);

int main() {
    int arr[] = {3,5,1,8,9,2,7,10,11,0};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int result[3];
    findThreeSmallestEven(arr,arraySize,result);
    printf("Smallest: %d, %d, %d\n", result[0], result[1], result[2]);

    return 0;
}



void findThreeSmallestEven(int arr[], int size, int result[]) {
    for (int i = 0; i < 3; i++) {
        result[i] = INT_MAX;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            for (int j = 0; j < 3; j++) {
                if (arr[i] < result[j]) {
                    for (int k = 2; k > j; k--) {
                        result[k] = result[k - 1];
                    }
                    result[j] = arr[i];
                    break;
                }
            }
        }
    }
}



void avgSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum = sum + arr[i];
    }
    float avg = (float)sum / size;

    printf("Sum of array: %d\nAvg of array: %f\n", sum, avg);
}





void findThreeLargest(int arr[], int size, int result[]) {
    for (int i = 0; i < 3; i++) {
        result[i] = INT_MIN;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i] > result[j]) {
                for (int k = 2; k > j; k--) {
                    result[k] = result[k - 1];
                }
                result[j] = arr[i];
                break;
            }
        }
    }
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