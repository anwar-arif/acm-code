#include<bits/stdc++.h>
using namespace std;

const int N = (int) 10000 + 10;
const int M = 55;

int n = 4, dp[N][M], sum;
int a[] = {2, 3, 7, 8};

bool subset_sum() {
    for (int i = 0; i <= n;i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - a[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
      sum = 11;
      bool dp[n + 1][sum + 1];

      bool can = subset_sum();
      printf("%s", can ? "Yes" : "No");
      return 0;
}

