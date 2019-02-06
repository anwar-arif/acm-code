#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

int main() {
//    freopen("in.txt" , "r" , stdin ) ;
    int n;

    while(scanf("%d", &n)==1)
    {
        for(int i=0; i<n; i++)
        {
            long long x, k;

            scanf("%lld %lld", &k, &x);

            long long ans = (k-1ll)*9ll+x;

            printf("%lld\n", ans);
        }
    }

    return 0 ;
}
