#include<stdio.h>

int main() {
    int arr[5] = {44, 70, 39, 21, 50};
    int temp, min_idx;
    for (int i = 0; i < 4; i++) {
        min_idx = i;
        for (int j = i + 1; j < 5; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


