#include <stdio.h>
#define MAX_SIZE 100  
void insertSorted(int arr[], int* size, int element) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    int i = *size - 1;
    while (i >= 0 && arr[i] > element) {
        arr[i + 1] = arr[i];  
        i--;
    }
    arr[i + 1] = element;
    (*size)++;
    printf("Step after adding %d: ", element);
    for (int j = 0; j < *size; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}
int main() {
    int sourceArray[] = {30, 10, 50, 40, 20};
    int sourceSize = sizeof(sourceArray) / sizeof(sourceArray[0]);
    int arr[MAX_SIZE]; 
    int size = 0; 
    for (int i = 0; i < sourceSize; i++) {
        insertSorted(arr, &size, sourceArray[i]);
    }
    printf("\nFinal sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}


#output
Step after adding 30: 30
Step after adding 10: 10 30
Step after adding 50: 10 30 50
Step after adding 40: 10 30 40 50
Step after adding 20: 10 20 30 40 50
Final sorted array:
10 20 30 40 50
