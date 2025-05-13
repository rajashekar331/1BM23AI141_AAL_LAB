#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    srand(time(0));
    int random_number = rand();
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
    printf("No match found. The random number %d is not in the list.\n", random_number);
    }
    return 0;
}
#output
Generated random number: 12345
Sorted list: 1 20 945 3002 66749 1000000 
No match found. The random number 12345 is not in the list.
