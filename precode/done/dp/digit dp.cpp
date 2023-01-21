#include<bits/stdc++.h>
using namespace std;

const int N = (int) 30 + 10;
const int inf = (int) 2e9;

vector <long long> inp;
long long dp[2][2][N][N];
int len;

long long F(bool isStart, bool cmp, int pos, int zero) {
    if (pos >= len) return zero;
    long long &ret = dp[isStart][cmp][pos][zero];
    if (ret != -1) return ret;

    int lim = cmp ? inp[pos] : 9;
    ret = 0;

    if (!isStart) {
        for (int i = 0; i <= lim; i++) {
            ret += F(isStart, cmp && (i == lim), pos + 1, zero + (i == 0));
        }
    } else {
        for (int i = 1; i <= lim; i++) {
            ret += F(0, cmp && (i == lim), pos + 1, zero + (i == 0));
        }
        ret += F(1, 0, pos + 1, 0);
    }

    return ret;
}

long long solve(long long x) {
    if (x < 0) return 0;
    if (x <= 9) return 1;
    inp.clear();
    while (x) {
        inp.push_back(x % 10);
        x /= 10;
    }
    reverse(inp.begin(), inp.end());
    len = (int) inp.size();
    memset(dp, -1, sizeof(dp));
    return F(1, 1, 0, 0) + 1;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int T, cas = 0; scanf("%d", &T);
    while (T--) {
        long long a, b; scanf("%lld %lld", &a, &b);
        long long answer = solve(b) - solve(a - 1);
        printf("Case %d: %lld\n", ++cas, answer);
    }
    return 0;
}

