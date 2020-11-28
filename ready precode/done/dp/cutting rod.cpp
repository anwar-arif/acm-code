#include <bits/stdc++.h>
using namespace std;

const int inf = (int) 2e9;

int solve(vector<int> &price) {
    int n = (int) price.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int max_val = -inf;

        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }

        dp[i] = max_val;
    }
    return dp[n];
}

int main() {
      vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

      int ans = solve(price);
      printf("maximum obtainable value %d\n", ans);

      return 0;
}
