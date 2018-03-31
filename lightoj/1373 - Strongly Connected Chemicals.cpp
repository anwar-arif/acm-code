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

#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

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

const int N = 100+5;

bool con[N][2*N] , visited[2*N];
vector<int>g[N],cat,ana,gr[N];
int match[2*N] , r,c;

bool dfs(int u){
    int len = SZ(gr[u]);
    for(int i = 0 ; i < len;i++){
        int v = gr[u][i];
        if(!visited[v]){
            visited[v] = true;
            if(match[v] < 0 or dfs(match[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm(){
    mem(match,-1);
    int len = SZ(cat);
    int cnt = 0;
    for(int i = 0 ; i< len;i++){
        int v = cat[i];
        mem(visited,false);
        if(dfs(v))++cnt;
    }
    return cnt;
}

int f(int i,int j){
    cat.clear();
    ana.clear();
    int p = SZ(g[i]);
    int q = SZ(g[j]);
    for(int k = 0; k < p;k++){
        ana.pb(g[i][k]);
    }
    for(int k = 0 ; k < q;k++){
        cat.pb(g[j][k]);
    }

    for(int x = 0 ; x < N;x++)gr[x].clear();

    for(int x = 0; x < q; x++){
        for(int y = 0; y < p;y++){
            int u = cat[x];
            int v = ana[y];
            if(!con[u][v]){
                gr[u].pb(v);
            }
        }
    }
    return p+q-bpm();
}

void reset(){
    for(int i = 0 ; i < N;i++){
        g[i].clear();
        for(int j = 0 ;j < 2*N;j++){
            con[i][j] = false;
        }
    }
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas = 0;
      sc1i(tst);
      while(tst--){
          sc2i(r,c);
          getchar();
          reset();
          char ch;
          for(int i = 1; i<= r;i++){
              for(int j = r+1;j <= r+c;j++){
                  sc("%c",&ch);
                  if(ch=='1'){
                      con[i][j] = true;
                      g[i].pb(j);
                      g[j].pb(i);
                  }
              }
              getchar();
          }
          int mx = 0;
          for(int i = 1; i<= r;i++){
              for(int j = r+1;j <= r+c;j++){
                  if(con[i][j]){
                      int x = f(i,j);
                      mx = max(mx,x);
                  }
              }
          }
          pf("Case %d: %d\n",++cas,mx);
      }
      return 0;
}
