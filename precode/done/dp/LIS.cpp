#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

int dp[N], arr[N], nxt[N], n;

int F(int i) {
    if (dp[i] != -1) return dp[i];
    int maxi = 0;

    for (int j = i + 1; j <= n; j++) {
        if (arr[j] > arr[i]) {
            int cur = F(j);
            if (cur > maxi) {
                maxi = cur;
                nxt[i] = j;
            }
        }
    }

    dp[i] = maxi + 1;
    return dp[i];
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    memset(dp, -1, sizeof(dp));
    memset(nxt, -1, sizeof(nxt));

    int lis = 0, starting = 0;

    for (int i = 1; i <= n; i++) {
        if (F(i) > lis) {
            lis = F(i), starting = i;
        }
    }

    printf("LIS is %d, starting from index %d\n", lis, starting);
    return 0;
}

/* Complexity: n ^ 2 */
