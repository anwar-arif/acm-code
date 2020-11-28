#include<bits/stdc++.h>
using namespace std;

const int inf = (int) 2e9;
const int mod = (int) 1e9 + 7;

int solve(int n, int k, vector<int> &coin) {
    vector<int> dp(k + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int val = coin[i];
        for (int j = k; j >= val; j--) {
            if (dp[j - val]) {
                dp[j] += dp[j - val];
                dp[j] %= mod;
            }
        }
    }
    return dp[k];
}

int main() {
    int T, cas = 0; scanf("%d", &T);
    while (T--) {
        int n, k; scanf("%d %d", &n, &k);

        vector<int> coin(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &coin[i]);
        }
        printf("Case %d: %d\n", ++cas, solve(n, k, coin));
    }
    return 0;
}
/*
input :
2
3 5
1 2 5
4 20
1 2 3 4
1
3 5
1 2 5

output :
Case 1: 4
Case 2: 108
*/
