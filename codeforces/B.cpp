#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

int n;
long long bits[70][3], m, csum[70];

int main() {
//    freopen("in.txt", "r", stdin);
    int T, cas = 0; scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &m);
        memset(bits, 0, sizeof(bits));
        for (int i = 0; i < n; i++) {
            long long x; scanf("%lld", &x);
            for (int j = 0; j < 55; j++) {
                if ((x & (1LL << j))) {
                    bits[j][1]++;
                } else {
                    bits[j][0]++;
                }
            }
        }
        csum[0] = min(bits[0][0], bits[0][1]);
        for (int j = 1; j < 55; j++) {
            csum[j] = csum[j - 1] + (min(bits[j][0], bits[j][1]) * (1LL << j));
        }
        long long answer = 0L, cur = 0L;
        int found = 0;
        for (int j = 51; j >= 0; j--) {
            if (j > 0 && csum[j - 1] > m) continue;
            if (j > 0 && csum[j - 1] + cur > m) continue;
            found = 1;
            long long one_cost = bits[j][0] * (1LL << j);
            if (j > 0) one_cost += csum[j - 1];
            if (cur + one_cost <= m) {
                answer |= (1LL << j);
                cur += bits[j][0] * (1LL << j);
            } else {
                cur += bits[j][1] * (1LL << j);
            }
        }
        if (answer == 0L) {
            long long cur = 0L;
            for (int i = 0; i < 52; i++) {
                cur += (bits[i][1] * (1LL << i));
            }
            if (cur > m) answer = -1L;
        }
        printf("Case #%d: %lld\n", ++cas, answer);
    }
    return 0 ;
}
