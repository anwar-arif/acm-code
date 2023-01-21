#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5;
const int inf = (int) 2e9;

int row[N], col[N], dp[N][N];

int rec(int beg, int end) {
    if (beg >= end)return 0;
    if (dp[beg][end] != -1) return dp[beg][end];

    int ans = inf;

    for (int mid = beg; mid < end; mid++) {
        int lft = rec(beg, mid);
        int rt = rec(mid + 1, end);

        int extra = row[beg] * col[mid] * cod[end];
        int total = lft + rt + extra;

        ans = min(ans, total);
    }

    return dp[beg][end] = ans;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &row[i], &col[i]);
    }

    printf("%d\n", rec(0, n - 1));

    return 0;
}

/* complexity = O(n^3) */
