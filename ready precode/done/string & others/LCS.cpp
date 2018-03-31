
const int N = 1000+5;

char a[N],b[N];
int dp[N][N],lenA,lenB;
string res;

int lcs(int i,int j)
{
    if(a[i] == '\0' or b[j] == '\0')return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(a[i] == b[j])
    {
        ans = 1 + lcs(i+1,j+1);
    }
    else
    {
        int p1 = lcs(i+1,j);
        int p2 = lcs(i,j+1);
        ans = max(p1,p2);
    }
    return dp[i][j] = ans;
}

void print_lcs(int i,int j)
{
    if(a[i] == '\0' or b[j] == '\0')
    {
        cout<<res<<endl;
        return;
    }
    if(a[i] == b[j])
    {
        res += a[i];
        print_lcs(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j] > dp[i][j+1])print_lcs(i+1,j);
        else print_lcs(i,j+1);
    }
}

string ans;

void printAll_lcs(int i,int j)
{
    if(a[i] == '\0' or b[j] == '\0')
    {
        cout<<ans<<endl;
        return;
    }
    if(a[i] == b[j])
    {
        ans += a[i];
        printAll_lcs(i+1,j+1);
        ans.erase(ans.end()-1);//delete last character
    }
    else
    {
        if(dp[i+1][j] > dp[i][j+1])printAll_lcs(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1])printAll_lcs(i,j+1);
        else if(dp[i+1][j] == dp[i][j+1])
        {
            printAll_lcs(i+1,j);
            printAll_lcs(i,j+1);
        }
    }
}

int main()
{
      sc("%s %s",&a,&b);
      mem(dp,-1);
      lenA = strlen(a);
      lenB = strlen(b);
      ans.clear();res.clear();
      pf("lcs %d\n",lcs(0,0));
      print_lcs(0,0);
      deb("all lcs");
      printAll_lcs(0,0);
      return 0;
}
///complexity = O(lenA*lenB)
