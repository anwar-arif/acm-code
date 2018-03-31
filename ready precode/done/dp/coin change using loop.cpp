int sum[10001],coin[101],n,k;

int rec(int k)// k = making value
{
      dp[0] = 1;

        for(ll i = 1 ; i <= n ; i++)//n = array size
        {
            ll val = coin[i] ;
            for(ll j = k; j >= val; j--){
                if(dp[j - val]){
                    dp[j] += dp[j - val] ;
                    dp[j] %= mod;
                }
            }
        }
}

int main()
{
        int tst,cas,ans,i;
        sc1i(tst);
        for(cas = 1;cas <= tst;cas++)
        {
            sc2i(n , k);

            memset(sum,0,sizeof(sum));

            for(i = 1 ; i <= n ; i++)
            {
                    sc1i( coin[i] );
            }

            ans = rec(k);

            pf("Case %d: %d\n",cas,ans);
        }
        return 0;
}

input :
2
3 5
1 2 5
4 20
1 2 3 4

output :
Case 1: 4
Case 2: 108
