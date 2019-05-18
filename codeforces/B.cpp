#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e3 + 10;
const int inf = (int) 2e9;

int k, n, m;
string tmp[5] = {
    "aeiou", "eioua", "iouae", "ouaei", "uaeio"
};

string vowel = "aeiou";

string s[N];

int can() {
    for (int i = 0; i < n; i++) {
        s[i] = tmp[i % 5];
    }
    for (int c = 5; c < m; c++) {
        for (int r = 0; r < n; r++) {
            s[r] += vowel[r % 5];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
    return 1;
}

int check(int k) {
    for (int i = 5; i * i <= k; i++) {
        if (k % i == 0) {
            if ((k / i) >= 5) {
                n = i, m = k / i;
                if (can() == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void solve() {
    if (check(k) == 0) {
        printf("-1\n");
        return;
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &k);
    solve();
    return 0 ;
}
