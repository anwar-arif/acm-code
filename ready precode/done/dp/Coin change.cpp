#include<bits/stdc++.h>
using namespace std;


int solve(int idx, int n, int make, vector<int> &coin,
    vector<vector<int>> &dp) {

    if (make < 0) return 0;
    if (idx >= n) return make == 0;

    int &ret = dp[idx][make];
    if (ret != -1) return ret;

    return ret = solve(idx, n, make - coin[idx], coin, dp)
                | solve(idx + 1, n, make, coin, dp);
}

int main() {
    int n, make; scanf("%d %d", &n, &make);
    vector<int> coin(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    vector<vector<int>> dp(n, vector<int>(make + 1, -1));
    printf("%s\n", solve(0, n, make, coin, dp) ? "True" : "False");

    return 0;
}

/* Complexity : O(number of coin * make) */
