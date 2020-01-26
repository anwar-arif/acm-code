#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

const long long base[] = {33LL, 163LL};
const long long mod[] = {10000007LL, 10000009LL};

// Hash and power values
long long H[2][N], P[2][N];
string s;

void init() {
    P[0][0] = P[1][0] = 1LL;
    H[0][0] = H[1][0] = 0LL;

    int n = (int) s.size();

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            P[i][j] = (base[i] * P[i][j - 1]) % mod[i];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            H[i][j] = (H[i][j - 1] * base[i] + (s[j] - 'a' + 1)) % mod[i];
        }
    }
}

long long getHash(int id, int l, int r) {
    int len = r - l + 1;
    return (H[id][r] - ((H[id][l - 1] * P[id][len]) % mod[id]) + mod[id]) % mod[id];
}

pair <long long, long long> getHashPair(int l, int r) {
    return {getHash(0, l, r), getHash(1, l ,r)};
}


int main() {
//    freopen("in.txt", "r", stdin);
    while (cin >> s) {
        init();
        int queries; scanf("%d", &queries);
        while (queries--) {
            int a, b; scanf("%d %d", &a, &b);
            int c, d; scanf("%d %d", &c, &d);
            if (b - a == d - c) {
                printf("%s\n", (getHashPair(a, b) == getHashPair(c, d)) ? "Yes" : "No");
            } else {
                printf("No");
            }
        }
    }
    return 0;
}
