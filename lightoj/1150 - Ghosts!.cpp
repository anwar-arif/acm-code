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
int dx[]= {0,0,1,-1};//4 side move
int dy[]= {-1,1,0,0};//4 side move
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

const int N = 25+5;

struct edge{
    int node,dist;
};

struct data{
    int x,y;
}ghost[55] , human[55];

char a[27][27];
vector<edge>gr[55];

int g , h , n , human_no[N][N] , d[55] , cost[55][55];
int match[55];
bool visited[N][N] , seen[55];

bool valid(int x,int y){
    if(x >= 1 and x <= n and y >= 1 and y <= n){
        if(a[x][y] != '#')return true;
        return false;
    }
    return false;
}

void bfs(int u,int v){
    visited[u][v] = true;

    int level[n+3][n+3];
    mem(level,-1);
    level[u][v] = 0;

    queue<pair<int,int> > q;
    q.push(MP(u,v));

    while(!q.empty()){
        pair<int,int> p;
        p = q.front(); q.pop();

        int x = p.first;
        int y = p.second;

        for(int i = 0 ;i < 4;i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(valid(X,Y) == true and !visited[X][Y]){
                level[X][Y] = level[x][y] + 1;
                visited[X][Y] = true;
                q.push(MP(X,Y));

                if(a[X][Y] == 'H'){
                    int t = human_no[X][Y];
                    d[t] = level[X][Y];
                }
            }
        }
    }
}

bool dfs(int u,int t){
    int len = SZ(gr[u]);
    for(int i = 0;i < len;i++){
        edge e = gr[u][i];
        int v = e.node;
        if(e.dist > t)continue;
        if(!seen[v]){
            seen[v] = true;
            if(match[v] == -1 or dfs(match[v],t)){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool bpm(int t){
    int cnt = 0;
    mem(match,-1);
    for(int i = 1; i<= g;i++){
        mem(seen,false);
        if(dfs(i,t))++cnt;
    }
    return cnt==h;
}


void reset(){
    for(int i = 0 ; i<55;i++){
        gr[i].clear();
        for(int j = 0;j < 55 ;j++){
            cost[i][j] = INT_MAX;
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
          sc1i(n);
          reset();
          g = h = 0;

          getchar();
          for(int i = 1; i<=n;i++){
              for(int j = 1;j <= n;j++){
                  sc("%c",&a[i][j]);
                  char ch = a[i][j];
                  if(ch == 'G'){
                      ++g;
                      ghost[g].x = i;
                      ghost[g].y = j;
                  }
                  if(ch == 'H'){
                      human_no[i][j] = ++h;
                      human[h].x = i;
                      human[h].y = j;
                  }
              }
              getchar();
          }

          for(int i = 1; i<=g;i++){
              mem(d,-1); mem(visited,false);
              bfs(ghost[i].x , ghost[i].y);

              edge e;
              for(int j = 1; j <= h;j++){
                  if(d[j] != -1){
                      e.node = j;
                      e.dist = 2*d[j] + 2;
                      gr[i].pb(e);
                      cost[i][j] = e.dist;
                  }
              }
          }

          int lo = 0, hi = n*n, mid;
          int ans = INT_MAX;;

          while(lo <= hi){
              mid = (lo + hi) / 2;
              if(bpm(mid) == true){
                  ans = mid;
                  ans = min(ans,mid);
                  hi = mid - 1;
              }else{
                  lo = mid + 1;
              }
          }

          if(ans == INT_MAX)pf("Case %d: Vuter Dol Kupokat\n",++cas);
          else pf("Case %d: %d\n",++cas,ans);
      }
      return 0;
}
