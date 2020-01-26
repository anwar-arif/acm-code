#include<bits/stdc++.h>
using namespace std;

const int N = (int) 3e5 + 10;
const int inf = (int) 2e9;

int n, m, x = 0, y = 0;
long long arr[N][11];

int can(long long val) {
    vector <int> indx[1 << m];
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] >= val) {
                mask |= (1 << j);
            }
        }
        indx[mask].push_back(i);
        if (mask == (1 << m) - 1) {
            x = i, y = i;
            return 1;
        }
    }
    for (int i = 0; i < (1 << m); i++) {
        if (indx[i].size() == 0) continue;
        for (int j = 0; j < (1 << m); j++) {
            if (indx[j].size() == 0) continue;
            if ((i | j) == (1 << m) - 1) {
                x = indx[i][0];
                y = indx[j][0];
                return 1;
            }
        }
    }
    return 0;
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &arr[i][j]);
        }
    }
    long long lo = 0, hi = (long long) 2e9, mid;
    int p = 0, q = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (can(mid)) {
            lo = mid + 1LL;
            p = x, q = y;
        } else {
            hi = mid - 1LL;
        }
    }
    printf("%d %d\n", p + 1, q + 1);
    return 0 ;
}
