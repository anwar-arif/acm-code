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

const int N = 70+5;

struct edge{
    int u,w;
    bool operator < (const edge &p)const{
        return w > p.w;
    }
};

vector<int>rg[N] , cost[N];
int path_cnt[N][N] , out[N] , n , level[N];

void reset(){
    for(int i = 0 ; i < N;i++){
        rg[i].clear();
        cost[i].clear();
        out[i] = 0;
        for(int j = 0 ; j< N;j++){
            path_cnt[i][j] = 0;
        }
    }
}

int dijkstra(int s){
    edge get;
    get.u = s;
    get.w = 0;
    priority_queue<edge>q;
    q.push(get);
    level[s] = 0;

    while(!q.empty()){
        edge top = q.top();
        q.pop();
        int u = top.u;
//        if(u == 0)return level[u];
        int len = SZ(rg[u]);
        for(int i = 0 ; i< len;i++){
            int v = rg[u][i];
            if(path_cnt[u][v] > 0 && level[v] > level[u]+cost[u][i]){
                --path_cnt[u][v];
//                deb("path ",u,v,path_cnt[u][v]);
                level[v] = level[u] + cost[u][i];
                get.u = v;
                get.w = level[v];
                q.push(get);
            }
        }
    }
    if(level[0] == INT_MAX)return -1;
    return level[0];
//    return ;
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int e,cas = 0 ,a,b,c;
      while(sc2i(n,e) != EOF){
          if(n + e == 0)break;
          reset();
          for(int i = 0 ; i < e;i++){
              sc3i(a,b,c);

              if(path_cnt[b][a] == 0){
                  cost[b].pb(c);
                  rg[b].pb(a);
              }
              ++path_cnt[b][a];
              ++out[b];
//              deb("path ",b,a,"=",path_cnt[b][a]);
          }
          pf("Instance #%d: ",++cas);
//          deb("debug ",out[n-1]);
          if(out[n-1] < 2)pf("Not possible\n");
          else{
//              deb("case = ",cas);
              int ans = 0 ;

              for(int i = 0 ;i < N;i++)level[i] = INT_MAX;
              int x = dijkstra(n-1);
              deb("x",x);

              for(int i = 0 ;i < N;i++)level[i] = INT_MAX;
              int y = dijkstra(n-1);
              deb("y",y);

              if(x >= 0 && y >= 0)pf("%d\n",x+y);
              else pf("Not possible\n");
          }
      }
      return 0;
}
