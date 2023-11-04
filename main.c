#include <stdio.h>
#include <limits.h> // Include limits.h for INT_MIN

void findThreeLargest(int arr[], int size, int result[]);
void findThreeSmallestEven(int arr[], int size, int result[]);
void avgSum(int arr[], int size);
void aboveMainD();
void numberArray();

int main1() {
    int arr[] = {3,5,1,8,9,2,7,10,11,0};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    numberArray();
    return 0;
}




void numberArray() {
    int arr[] = {3, 5, 1, 8, 3, 2, 7, 3, 11, 0};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int num;

    printf("Enter the integer: ");
    scanf("%d", &num);
    printf("Entered integer is: %d\n", num);

    int positions[arraySize]; // An array to store positions
    int positionCount = 0; // A counter for positions found

    for (int i = 0; i < arraySize; ++i) {
        if (arr[i] == num) {
            positions[positionCount] = i;
            positionCount++;
            printf("Lol %d", positionCount);
        }
    }

    if (positionCount > 0) {
        printf("The integer %d was found at positions: ", num);
        for (int i = 0; i < positionCount; ++i) {
            printf("%d", positions[i]);
            if (i < positionCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("The integer %d was not found in the array.\n", num);
    }
}


void aboveMainD() {
    int m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int columns = 3;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if(i<j) {
                printf("%d ", m1[i][j]);
            }
        }
    }
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