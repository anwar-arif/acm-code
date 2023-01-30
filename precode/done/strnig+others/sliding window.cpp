# include <bits/stdc++.h>
using namespace std;
const int N = 300000+5;

int a[N] , sum[N];

int main()
{
    int n ,k;
    while(sc2i(n,k) != EOF){

        mem(sum,0);

        for(int i =  1 ;i <= n;i++){
            sc1i(a[i]);
            sum[i] += a[i]!=1;
        }

        int mx = 0 ,hi = 1 , l , r;
        int tot = 0;

        for(int i =  1 ;i <= n;i++){

            while(tot + sum[hi] <= k && hi <= n){
                tot += sum[hi];
                ++hi;
            }

            if(hi - i > mx){
                mx = hi - i;
                l = i ; r = hi;
            }

            tot -= sum[i];
        }

        for(int i =  lo ;i <= hi - 1;i++)a[i] = 1;
        pf("%d\n",mx);

        for(int i =  1 ;i <= n;i++)pf("%d ",a[i]);
        pf("\n");
    }
    return 0;
}

//complexity O(2n)
/*
in
7 1
1 0 0 1 1 0 1
out
4
1 0 0 1 1 1 1
*/
