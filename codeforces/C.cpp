#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e8;

int n, arr[N];

int F(int lo) {
    int hi = n, mid, ans = -1, x = arr[lo];
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (arr[mid] <= x + x) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int solve(int l) {
    int x = F(l);
    if (x < 0) return 0;
    return (x - l);
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x < 0) arr[i] = -x;
        else arr[i] = x;
    }
    sort(arr + 1, arr + 1 + n);
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += solve(i);
    }
    printf("%lld\n", answer);
    return 0 ;
}
