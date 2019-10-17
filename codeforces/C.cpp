#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 10;
const int inf = (int) 2e9;

char seq[N];
int dp[N][10][10], vis[N][10][10], n, cas = 0;

int F(int p, int f, int s, int m) {
    if (p == n) return 1;
    int &ret = dp[p][f][s];
    if (vis[p][f][s] == cas) return ret;
    vis[p][f][s] = cas, ret = 0;
    int c = (seq[p] - '0');
    if (c >= f && c <= m) ret |= F(p + 1, c, s, m);
    if (c >= s) ret |= F(p + 1, f, c, m);
    return ret;
}

void path(int p, int f, int s, int m) {
    if (p == n) {
        printf("\n");
        return;
    }
    int c = seq[p] - '0';
    if (c >= f && c <= m && F(p + 1, c, s, m)) {
        printf("1");
        path(p + 1, c, s, m);
        return;
    }
    if (c >= s && F(p + 1, f, c, m)) {
        printf("2");
        path(p + 1, f, c, m);
        return;
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", &seq);
        int can = 0;
        for (int i = 0; i < 10; i++) {
            cas += 1;
            can |= F(0, 0, i, i);
            if (can) {
                path(0, 0, i, i);
                break;
            }
        }
        if (!can) printf("-\n");
    }
    return 0 ;
}
