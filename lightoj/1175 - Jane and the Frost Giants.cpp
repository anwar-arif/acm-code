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

const int N = 200+5;

char a[N][N];

int r,c;

struct data{
    int x,y;
}fire[40000+5];

int Fire[N][N] , level[N][N];
bool visited[N][N];

bool valid(int x,int y){
    if(a[x][y] !='#' && x >= 1 && x <= r && y >= 1 && y <= c && !visited[x][y])return true;
    return false;
}

void bfs(int sx,int sy){
    mem(visited,false);

    pair<int,int>p;
    queue<pair<int,int> >q;

    q.push(MP(sx,sy));
    visited[sx][sy] = true;
    Fire[sx][sy] = 0;

    while(!q.empty()){
        p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;

        for(int i = 0 ; i < 4;i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(valid(X,Y)){
                if(Fire[X][Y] >= Fire[x][y]+1){
                    Fire[X][Y] = Fire[x][y] + 1;
                    visited[X][Y] = true;
                    q.push(MP(X,Y));
                }
            }
        }
    }
}

bool isvalid(int x,int y){
    if(x >= 1 && x <= r && y >= 1 && y <= c && a[x][y] != '#' && !visited[x][y])return true;
    return false;
}

int bfs2(int sx,int sy){
    mem(visited,false);
    level[sx][sy] = 0;
    queue<pair<int,int> > q;
    q.push(MP(sx,sy));
    visited[sx][sy] = true;
    pair<int,int> p;

    while(!q.empty()){
        p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;
        if(x == 1 or x == r or y == 1 or y == c)return level[x][y]+1;
        for(int i = 0 ; i< 4;i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(isvalid(X,Y) && Fire[X][Y] > level[x][y] + 1){
                level[X][Y] = level[x][y] + 1;
                visited[X][Y] = true;
                q.push(MP(X,Y));
            }
        }
    }
    return -1;
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
          int k = 0;
          int sx,sy;
          for(int i = 1;i <= r;i++){
              for(int j = 1;j <= c;j++){
                  sc("%c",&a[i][j]);
                  Fire[i][j] = INT_MAX;
                  if(a[i][j] == 'J'){
                    sx = i,sy = j;
                  }
                  else if(a[i][j] == 'F'){
                     ++k;
                     fire[k].x = i;
                     fire[k].y = j;
                  }
              }
              getchar();
          }
          for(int i = 1; i <= k;i++){
              bfs(fire[i].x,fire[i].y);
          }

          int ans = bfs2(sx,sy);
          if(ans == -1)pf("Case %d: IMPOSSIBLE\n",++cas);
          else pf("Case %d: %d\n",++cas,ans);
      }
      return 0;
}


