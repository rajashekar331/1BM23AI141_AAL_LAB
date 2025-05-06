#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXN 16

int dp[1 << MAXN][MAXN];

int totalCost(int mask, int pos, int n, int cost[MAXN][MAXN]) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0]; 
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int newAns = cost[pos][city] + totalCost(mask | (1 << city), city, n, cost);
            if (newAns < ans) ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int tsp(int n, int cost[MAXN][MAXN]) {
    memset(dp, -1, sizeof(dp));
    return totalCost(1, 0, n, cost); 
}

int main() {
    int cost[MAXN][MAXN] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = 4; 
    int result = tsp(n, cost);
    printf("Minimum TSP cost: %d\n", result);

    return 0;
}

