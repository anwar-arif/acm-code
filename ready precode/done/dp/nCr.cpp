#define mx 70

i64 dp[mx][mx];

i64 nCr(int n,int r)
{
    if(r==1) return n;

    if(n==r) return 1;

    if(dp[n][r]!=-1) return dp[n][r];

    else
    {
        dp[n][r] = nCr( n-1 , r ) + nCr( n-1 , r-1);

        return dp[n][r];
    }
}
int main()
{
    memset(dp,-1);
    printf("%d\n",nCr(20,2));
}
