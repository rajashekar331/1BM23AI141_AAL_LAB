#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int arr[], int n) {
    clock_t start, end;
    double time_spent;
    start = clock();
    int total_operations = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            total_operations++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    end = clock();
    time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for sorting: %f seconds\n", time_spent);
    printf("Total operations (comparisons/swaps): %d\n", total_operations);
}
int main() {
    srand(time(0));
    int random_number = rand() % 1000 + 1;
    printf("Generated random number: %d\n", random_number);
    int list[] = {20, 3002, 1, 945, 66749, 1000000};
    int n = sizeof(list) / sizeof(list[0]);
    bubbleSort(list, n);
    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (random_number == list[i]) {
            printf("Match found! Random number %d is in the list.\n", random_number);
            return 0;
        }
    }
    printf("No match found. The random number %d is not in the list.\n", random_number);
    return 0;
}

