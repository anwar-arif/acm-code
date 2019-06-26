#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

long long arr[N], brr[N], n, m, ta, tb, k;

void no() {
    cout << -1 << endl;
    exit(0);
}

long long F(int x) {
    long long which = arr[x + 1];
    int lo = 1, hi = m, mid, ans = inf;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (brr[mid] >= which) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += ta;
    }
    for (int i = 1; i <= m; i++) {
        cin >> brr[i];
    }
    if (k >= n || k >= m) {
        no();
    }
    long long answer = (long long) 2e14;
    answer *= -1LL;
    for (int i = 0; i <= k; i++) {
        int idx = F(i) + k - i;
        if (idx > m) no();
        answer = max(answer, brr[idx] + tb);
    }
    cout << answer << endl;
    return 0 ;
}
