#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e2 + 10;
const int M = (int) 1e4 + 10;
const int inf = (int) 2e9;

int n, dp[N][M], weight[N], cost[N], capacity;

int F(int i, int w) {
    if (i == n + 1) return 0;
    int &ret = dp[i][w];
    if (ret != -1) return ret;

    int p1 = 0, p2 = 0;
    if (w + weight[i] <= capacity) {
        p1 = cost[i] + F(i + 1, w + weight[i]);
    }
    p2 = F(i + 1, w);

    return ret = max(p1, p2);
}

int main() {
//    freopen("in.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &capacity);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &weight[i], &cost[i]);
    }
    printf("%d\n", F(1, 0));

    return 0;
}

/* Complexity : O(n*cap) ; n = number of things. cap = capacity */
