#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e8;

char s[N];
int n, m;
long long dp[(1 << 20)], cnt[30][30];

long long F(int mask, int p) {
    if (p == m) return 0L;
    long long &ret = dp[mask];
    if (ret != -1) return ret;
    ret = (long long) inf;
    for (int i = 0; i < m; i++) {
        if (!(mask & (1 << i))) {
            long long add = 0L;
            for (int j = 0; j < m; j++) {
                if (i != j) {
                    if (mask & (1 << j)) {
                        add += p * cnt[i][j];
                    } else {
                        add -= p * cnt[i][j];
                    }
                }
            }
            ret = min(ret, add + F(mask | (1 << i), p + 1));
        }
    }
    return ret;
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    scanf("%s", &s);
    memset(cnt, 0L, sizeof(cnt));
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < n; i++) {
        int u = s[i - 1] - 'a';
        int v = s[i] - 'a';
        cnt[u][v]++, cnt[v][u]++;
    }
    printf("%lld\n", F(0, 0));
    return 0 ;
}
