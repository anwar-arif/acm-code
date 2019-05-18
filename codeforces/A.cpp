#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e3 + 10;
const int inf = (int) 2e9;

int n, cnt[N];
string s;

int main() {
//    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < 26; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cnt[s[0] - 'a'] += 1;
    }
    int mx = 0, ans = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] <= 1) continue;
        mx = cnt[i];
        int p = mx / 2, q = mx - p;
        ans += (p * (p - 1)) / 2;
        ans += (q * (q - 1)) / 2;
    }
    cout << ans << endl;
    return 0 ;
}
