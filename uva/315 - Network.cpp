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
//int dx[]= {0,0,1,-1};//4 side move
//int dy[]= {-1,1,0,0};//4 side move
//int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
//int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
int dx[]={1,1,2,2,-1,-1,-2,-2};//knight move
int dy[]={2,-2,1,-1,2,-2,1,-1};//knight move

template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}//N^P
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}//gcd(a,b)

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<< v <<" ";
        return *this;
    }
}dbg;
#define deb(args...) {dbg,args; cerr<<endl;}

void make_unique(vector<int> &a){ sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); }

//ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

//int on(int n,int pos){return n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = 500 + 5;

vector<int>g[N] ;

bool vis[N] , art[N];

int par[N] , dis[N] , fin[N] , depth;
char s[N] ;

void reset(){
    depth = 0;
    rep(i,0,N-2){
        g[i].clear();
        vis[i] = false;
        par[i] = -1;
        art[i] = false;
    }
}

void dfs(int u){
    vis[u] = true;
    dis[u] = fin[u] = depth++;
    int child = 0;
    int len = SZ(g[u]);
    for(int i = 0 ;i < len ;i++){
        int v = g[u][i] ;
        if(!vis[v]){
            ++child;
            par[v] = u;
            dfs(v) ;
            dis[u] = min(dis[u] , dis[v]);
            if(par[u] != -1){
                if(dis[v] >= fin[u]){
                    art[u] = true;
                }
            }
        }
        else if(v != par[u]){
            dis[u] = min(dis[u] , fin[v]);
        }
    }
    if(par[u] == -1){
        if(child > 1){
            art[u] = true;
        }
    }
}

void cal(char s[]){
    int len = strlen(s) ;
    int u = 0 , v = 0 , cur = 0;
    rep(i,0,len-1){
        if(s[i] >= '0' && s[i] <= '9'){
            cur = cur*10 + (s[i] - '0');
        }
        else{
            if(!u){
                u = cur;
            }
            else{
                g[u].pb(cur) ;
                g[cur].pb(u);
            }
            cur = 0;
        }
    }
    if(u){
        if(cur){
            g[u].pb(cur) ;
            g[cur].pb(u);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int n;
    while(sc1i(n) != EOF){
        if(n == 0)break;
        reset();
        getchar();
        while(fgets(s,N,stdin)){
            if(s[0] == '0')break;
            s[strlen(s)] = '\0';
            cal(s);
        }
        rep(i,1,n){
            if(!vis[i])dfs(i);
        }
        int ans = 0;
        rep(i,1,n){
            ans += (art[i] == true) ;
        }
        pf("%d\n",ans);
    }
    return 0;
}
