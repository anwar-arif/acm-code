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
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
int dx[]= {0,0,1,-1};//4 side move
int dy[]= {-1,1,0,0};//4 side move
//int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
//int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
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

void make_unique(vector<ll> &a){ sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); }
//ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

//int on(int n,int pos){return n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = 1e4 + 10;
const ll inf = 2e13 ;

string str ;
bool t ;
int root , tot = 10 ;
ll dp[N][20];

vector < int > g[N] ;

void cal(int u){
    int x = -1 , len = SZ( str );
    for(int i = 0 ;i < len ;i++){
        if(isdigit( str[i] )){
            if(x < 0)x = str[i] - '0' ;
            else x = x*10 + (str[i] - '0');
        }
        else{
            if(x >= 0){
                g[u].pb(x);
                g[x].pb(u);
                if(!t){
                    root = u ; t = true ;
                }
                x = -1 ;
            }
        }
    }
    if(x >= 0){
        g[u].pb(x);
        g[x].pb(u);
    }
}

ll dfs(int u , int p , int col){
    if(dp[u][col] != -1)return dp[u][col] ;

    int len = SZ( g[u] );
    ll mn = inf ;

    for(int i = 1 ;i <= tot ;i++){
        if(i != col){
            ll sum = (ll)i ;
            for(int j = 0 ;j < len ;j++){
                int v = g[u][j] ;
                if(v != p){
                    sum += dfs(v , u , i) ;
                }
            }
            mn = min( mn , sum ) ;
        }
    }
    return dp[u][col] = mn ;
}

void reset(){
    for(int i = 0 ;i < N-2 ;i++){
        g[i].clear() ;
    }
}

int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" , stdin);
//    #endif
    int n , u  ;
    while(sc1i( n ) != EOF){
        if(n == 0 )break ;
        reset() ;
        t = false ;
        for(int i = 1; i <= n;i++){
            sc("%d:",&u);
            getline(cin , str);
            cal(u);
        }
        ll mn = inf ;
        mem( dp , -1 ) ;
        mn = dfs(1 , -1 , 0) ;
        pf("%lld\n",mn);
    }
    return 0;
}

