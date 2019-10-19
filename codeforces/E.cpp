#include<bits/stdc++.h>
using namespace std;

const int N = (int) 55;
const int inf = (int) 2e8;

int dp[N][N][N][N], n;
int csum[N][N], arr[N][N];
char s[N][N];

void calc() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i + 1][j + 1] = s[i][j] == '#';
        }
    }
    memset(csum, 0, sizeof(csum));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            csum[i][j] = csum[i - 1][j] + csum[i][j - 1] - csum[i - 1][j - 1] + arr[i][j];
        }
    }
}

int black(int x1, int y1, int x2, int y2) {
    int res = csum[x2][y2] - csum[x2][y1 - 1] - csum[x1 - 1][y2] + csum[x1 - 1][y1 - 1];
    return res;
}

int F(int x1, int y1, int x2, int y2) {
    if (black(x1, y1, x2, y2) == 0) return 0;
    int &ret = dp[x1][y1][x2][y2];
    if (ret != -1) return ret;
    ret = max(x2 - x1 + 1, y2 - y1 + 1);
    for (int x = x1; x < x2; x++) {
        ret = min(ret, F(x1, y1, x, y2) + F(x + 1, y1, x2, y2));
    }
    for (int y = y1; y < y2; y++) {
        ret = min(ret, F(x1, y1, x2, y) + F(x1, y + 1, x2, y2));
    }
    return ret;
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &s[i]);
    }
    calc();
    memset(dp, -1, sizeof(dp));
    printf("%d\n", F(1, 1, n, n));
    return 0 ;
}
