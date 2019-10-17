#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

int cnt[N], n, mx = (int) 1e5;
char s[N];

int main() {
//    freopen("in.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    scanf("%s", &s);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        int on = (s[i] == '1');
        int nxt = b;
        for (int j = 0; j <= mx; j += 1) {
            if (j == nxt) {
                on ^= 1;
                nxt += a;
            }
            cnt[j] += on;
        }
    }
    int ans = 0;
    for (int i = 0; i <= mx; i++) {
        ans = max(ans, cnt[i]);
    }
    printf("%d\n", ans);
    return 0 ;
}
