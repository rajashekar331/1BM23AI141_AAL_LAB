#include <iostream>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left+1 ;
    int n2 = right - mid ;
    
    int * L = new int[n1];
    int * R = new int[n2];
    
    for(int i=0;i<n1;i++)
       L[i]= arr[left+i];
    for(int j=0;j<n2;j++)
       R[j]= arr[mid+1+j];
       
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L; delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Sorted array: ";
    printArray(arr, arr_size);
    
    return 0;
}
