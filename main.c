#include <stdio.h>

int main() {
    int arr[] = {3, 5, 8, 6, 2, 7, 10, 11};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int min, max = arr[0];
//    printf("%d\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        if(arr[i] < i)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    printf("Smallest elem: %d\n and biggest elem: %d\n", min, max);
    return 0;
}
