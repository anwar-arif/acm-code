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
#define dbl double

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
#define p_inf INT_MAX
#define n_inf INT_MIN
#define ppcnt(a) __builtin_popcount(a)
#define cnttz(a) __builtin_ctz(a)
#define cntlz(a) __builtin_clz(a)

#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};//4 side move
//int dy[]= {-1,1,0,0};//4 side move
//int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
//int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
//int dx[]={1,1,2,2,-1,-1,-2,-2};//knight move
//int dy[]={2,-2,1,-1,2,-2,1,-1};//knight move

template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}//N^P
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}//gcd(a,b)

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}


//void on(int &n,int pos){ n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

#define SIZ 20000+5

vector<int>g[SIZ];
stack<int>st;
int dis[SIZ],fin[SIZ],depth,belong[SIZ],scc;

void reset(int n){
    for(int i = 0 ; i <=n+2;i++){
        g[i].clear();
        dis[i] = fin[i] = belong[i] = -1;
    }
    while(!st.empty())st.pop();
}

void tarjan(int u){
    dis[u] = fin[u] = ++depth;
    st.push(u);
    int len = SZ(g[u]);
    for(int i = 0 ; i < len;i++){
        int v = g[u][i];
        if(fin[v] == -1){
            tarjan(v);
            dis[u] = min(dis[u],dis[v]);
        }
        else if(belong[v] == -1){
            dis[u] = min(dis[u],fin[v]);
        }
    }
    if(dis[u] == fin[u]){
        ++scc;
        int v;
        do{
            v = st.top(); st.pop();
            belong[v] = scc;
        }while(v != u);
    }
}

int cal(int n){
    for(int i = 1; i<=n;i++){
        if(fin[i] == -1)tarjan(i);
    }
    if(scc == 1)return 0;
    bool in[n+2],out[n+2];
    mem(in,false);  mem(out,false);
    for(int i = 1;i <= n;i++){
        int len = SZ(g[i]);
        for(int j = 0;j<len;j++){
            int v = g[i][j];
            if(belong[i] != belong[v]){
                in[belong[v]] = true;
                out[belong[i]] = true;
            }
        }
    }
    int a = 0,b=0;
    for(int i = 1;i<=scc;i++){
        if(in[i] == false)++a;
        if(out[i] == false)++b;
    }
    return max(a,b);
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas = 0,a,b,n,m;
      sc1i(tst);
      while(tst--){
        sc2i(n,m);
        reset(n);
        for(int i = 1;i<=m;i++){
            sc2i(a,b);
            g[a].pb(b);
        }
        depth = 0 , scc = 0;
        int ans = cal(n);
        pf("Case %d: %d\n",++cas,ans);
      }
      return 0;
}
