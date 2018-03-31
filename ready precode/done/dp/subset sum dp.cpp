
const int N = 10000+5;

int n = 4 , dp[10][50] , sum ;
int a[] = {2, 3, 7, 8};///n = 4

bool subset_sum(){
    for(int i = 0; i <= n;i++){
        dp[i][0] = true;
    }
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<= sum;j++){
            if( j - a[i - 1] >= 0){
                dp[i][j] = dp[i - 1][j] || dp[i-1][j - a[i - 1]];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
      sum = 11;
      bool dp[n+1][sum+1];

      bool t = subset_sum();
      pf("%s",t?"oka":"no");
      return 0;
}
///
