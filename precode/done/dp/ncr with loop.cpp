#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 1e3 + 10 ;
const int inf = (int) 2e9 ;

const long long mod = (long long) 998244353 ;

long long C[N][N] ;

void calc() {
    for (int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 0; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

int main() {
    calc();
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        printf("%lld\n", C[n][k] ) ;
    }
    return 0 ;
}
