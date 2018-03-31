#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
const long long mod = 1000000007;
typedef long long ll;
/**
dp[i] = number of distnct subseq ending with s[i]
last[i] = last position of char i in the given string
**/

char s[N] ;
ll dp[N] , last[500];

int main(){
    int tst ;
    scanf("%d",&tst);
    while(tst--){
        scanf("%s",s);
        int len = strlen(s);
        memset(last , -1 , sizeof(last));
        dp[0] = 1;
        for(int i = 1;i <= len ;i++){
            dp[i] = (dp[i-1] * 2) % mod;
            ///if current char appeared before remove all
            ///ending with prev occurence
            if( last[s[i-1]] != -1 ){
                dp[i] -= (dp[ last[ s[i-1] ] ]);
                dp[i] += mod;
                dp[i] %= mod;
            }
            last[s[i-1]] = (i-1);
        }
        printf("%lld\n",dp[len] % mod);
    }
    return 0;
}
/**
3
AAA
ABCDEFG
CODECRAFT
**/
/**
4
128
496
**/
