#include<bits/stdc++.h>
using namespace std;

char s1[2005],s2[2005];
int dp[2005][2005];

int min(int x, int y, int z)
{
   return min(min(x, y), z);
}

int ED(int m,int n)
{
    for(int i = 0;i<=m;i++)dp[i][0] = i;
    for(int i = 0;i<=n;i++)dp[0][i] = i;
    for(int i = 1 ; i<= m;i++)
    {
        for(int j = 1 ; j <= n;j++)
        {
            if(s1[i-1] == s2[j-1])dp[i][j] = dp[i-1][j-1];
            else
            {
                dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst;
      sc1i(tst);
      while(tst--)
      {
          sc("%s",s1);sc("%s",s2);
          int m = strlen(s1);
          int n = strlen(s2);
          int ans = ED(m,n);
          pf("%d\n",ans);
      }
      return 0;
}
