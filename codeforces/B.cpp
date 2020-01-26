#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

long long arr[N];

int main() {
//    freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &arr[i]);
        }
        long long pref = 0, suf = 0, can = 1;
        for (int i = 1, j = n; i <= n; i++, j--) {
            pref += arr[i];
            suf += arr[j];
            if (pref <= 0 || suf <= 0) {
                can = 0;
                break;
            }
        }
        printf("%s\n", can ? "YES" : "NO");
    }
    return 0;
}
