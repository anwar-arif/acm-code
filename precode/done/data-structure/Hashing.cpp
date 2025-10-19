#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

struct StringHash {
    const long long base[2] = {33LL, 163LL};
    const long long mod[2] = {10000007LL, 10000009LL};

    vector<vector<long long>> hash, power;
    int len;
    string s;

    StringHash(string _s) {
        s = _s;
        len = (int) s.size();
        hash = vector<vector<long long>> (2, vector<long long> (len + 1));
        power = vector<vector<long long>> (2, vector<long long> (len + 1));

        build();
    }

    void build() {
        power[0][0] = power[1][0] = 1LL;
        hash[0][0] = hash[1][0] = 0LL;

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= len; j++) {
                power[i][j] = (base[i] * power[i][j - 1]) % mod[i];
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= len; j++) {
                hash[i][j] = (((hash[i][j - 1] * base[i]) % mod[i]) + (s[j - 1] - 'a' + 1)) % mod[i];
            }
        }
    }

    long long getHash(int id, int l, int r) {
        int n = r - l + 1;
        return ((hash[id][r] - ((hash[id][l - 1] * power[id][n]) % mod[id])) + mod[id]) % mod[id];
    }

    pair<long long, long long> getHash(int l, int r) {
        return {getHash(0, l, r), getHash(1, l , r)};
    }
};

int main() {
//    freopen("in.txt", "r", stdin);
    string s;
    while (cin >> s) {
        StringHash sh(s);
        int queries; scanf("%d", &queries);
        while (queries--) {
            int a, b; scanf("%d %d", &a, &b);
            int c, d; scanf("%d %d", &c, &d);
            if (b - a == d - c) {
                printf("%s\n", (sh.getHash(a, b) == sh.getHash(c, d)) ? "Yes" : "No");
            } else {
                printf("No");
            }
        }
    }
    return 0;
}
