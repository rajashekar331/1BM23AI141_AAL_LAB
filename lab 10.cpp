#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int tsp(int cost[][4], int numNodes) {
    int nodes[numNodes - 1];
    int minCost = INT_MAX;
    for (int i = 1; i < numNodes; i++) {
        nodes[i - 1] = i;
    }
    do {
        int currCost = 0;
        int currNode = 0;
        for (int i = 0; i < numNodes - 1; i++) {
            currCost += cost[currNode][nodes[i]];
            currNode = nodes[i];
        }
        currCost += cost[currNode][0];
        if (currCost < minCost) {
            minCost = currCost;
        }
    } while (next_permutation(nodes, numNodes - 1));

    return minCost;
}
bool next_permutation(int arr[], int n) {
    int i = n - 1;
    while (i > 0 && arr[i - 1] >= arr[i]) {
        i--;
    }
    if (i == 0) {
        return false;  
    }
    int j = n - 1;
    while (arr[j] <= arr[i - 1]) {
        j--;
    }
    int temp = arr[i - 1];
    arr[i - 1] = arr[j];
    arr[j] = temp;
    int left = i, right = n - 1;
    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    return true;
}
int main() {
    int cost[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int res = tsp(cost, 4);
    printf("%d\n", res);
    return 0;
}
#output
80
