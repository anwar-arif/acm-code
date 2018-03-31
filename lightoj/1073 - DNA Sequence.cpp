#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
#include <fstream>
#include <climits>
#include <complex>
#include <new>
#include <memory>
#include <time.h>
//#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int
#define ull unsigned ll

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define pb push_back
#define pi acos(-1.0)
#define mem(a,x) memset(a,x,sizeof(a))
#define all(v) v.begin(),v.end()
#define SZ(a) (int)a.size()
#define MP make_pair
#define sqr(a) ((a)*(a))
#define ppcnt(a) __builtin_popcount(a)
#define cnttz(a) __builtin_ctz(a)
#define cntlz(a) __builtin_clz(a)

#define rep(i,k,n) for(__typeof(n)i = k ; i <= n; i++)
#define rrep(i,k,n) for(__typeof(k)i = k ; i >= n; i--)
#define show(a) cerr <<#a<< " = " << a << endl;

#define wait system("pause")
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};//4 side move
//int dy[]= {-1,1,0,0};//4 side move
int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
//int dx[]={1,1,2,2,-1,-1,-2,-2};//knight move
//int dy[]={2,-2,1,-1,2,-2,1,-1};//knight move

template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}//N^P
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}//gcd(a,b)

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<< v <<" ";
        return *this;
    }
}dbg;
#define deb(args...) {dbg,args; cerr<<endl;}

void make_unique(vector<string> &a){ sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); }
ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

int on(int n,int pos){return n=n|(1<<pos);}
void off(int &n,int pos){ n = n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
////N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = (int)1e5 + 10;

char s[20][110] ;

int lps[N+5];

char text[110] , pat[110] ;

void cal_lps(){
    int indx = 0;
    lps[0] = 0;
    int len = strlen( pat ) ;
    for(int i = 1 ;i < len; ){
        if(pat[i] == pat[indx]){
            lps[i] = indx + 1;
            i++; indx++;
        }
        else{
            if(indx != 0){
                indx = lps[indx - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmp( int ii , int jj ) {

    strcpy( text , s[ii] ) ;
    strcpy( pat , s[jj] ) ;

    cal_lps();
    int i = 0 , j = 0 ;
    int cnt  = 0;
    ///i for text and j for pat
    int textLen = strlen( text ) ;
    int patLen = strlen( pat ) ;

    while(i < textLen ){
        if(pat[j] == text[i]){
            i++; j++;
        }
        if(j == patLen ){
//            pf("pat found at %d\n",i - j);
            j = lps[j - 1];
        }
        else if(i < textLen && pat[j] != text[i]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return j ;
}

int match[20][20] , n , cas ;
int sz[20] ;
int mn , dp[17][1<<17] , vis[17][1<<17] ;

int rec( int pos , int mask , int pre ) {
    if( (1 << n ) == mask+1 ){
         dp[pos][mask] = sz[pos] - pre ;
         return sz[pos] ;
    }
    int &ret = dp[pos][mask] ;
    int &v = vis[pos][mask] ;
    if( v == cas ) return ret ;
    v = cas ;
    ret = 100000 ;
    for( int i = 0 ;i < n ; i++ ) {
        if( check( mask , i ) == 0 ) {
            ret = min( ret , sz[pos] + rec( i , on( mask , i ) , match[pos][i] ) - match[pos][i]  ) ;
        }
    }
    return ret ;
}

string ans ;

void srch( int cstart , int pos , int mask , int pre , string cur ) {
//    deb("srch" , pos , mask , dp[pos][mask] ) ;
    string tmp = "" ;
    for( int i = cstart ; i < sz[pos] ; i++ ) {
        tmp += s[pos][i] ;
    }
    if( ( 1 << n ) == mask+1 ) {
        ans = min( ans , cur+tmp ) ;
        return ;
    }
    for( int i = 0 ; i < n ; i++ ) {
        if( check( mask , i ) == 0 ) {
            deb( pos , mask , dp[pos][mask] );
            if( dp[pos][mask] + pre == mn ) {srch( match[pos][i] , i , on( mask , i ) , pre+sz[pos]-cstart , cur+tmp ) ;}
//            srch( match[pos][i] , i , on( mask , i ) , pre+sz[pos]-cstart , cur+tmp ) ;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" , stdin);
    #endif
    int tst ;
    mem( vis , 0 ) ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        scanf("%d" , &n ) ;
        ++cas ;
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%s" , &s[i] ) ;
            sz[i] = strlen( s[i] ) ;
        }
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( i != j ) {
                    match[i][j] = kmp( i , j ) ;
                }
            }
        }
        mn = 100000 ;
        for( int i = 0 ; i < n ; i++ ) {
            mn = min( mn , rec( i , on( 0 , i ) , 0 ) ) ;
        }
        deb("mn" , mn ) ;
        ans = "" ;
        for( int i = 1 ; i < 110 ; i++ ) ans += "z" ;
    }
//   cerr << clock() << " ms" << endl;
    return 0;
}

