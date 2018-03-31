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

#define SIZ 10000+5

int r,c;
string s[25];
bool visited[25][25];

bool valid(int x,int y)
{
    if(x>=0 and x<r and y<c and y>=0)
    {
        if(visited[x][y]==false and s[x][y]!='m' and s[x][y]!='#')
        {
            return true;
        }
    }
    return false;
}

int bfs(int a,int b)
{
    queue<pair<int,int> > q;

    q.push(MP(a,b));
    int dst[r+2][c+2];

    mem(visited,false);
    visited[a][b] = true;
    dst[a][b] = 0;
    int mx = 0;

    while(!q.empty())
    {
        pair<int,int> p;
        p = q.front();q.pop();
        int x = p.first;
        int y = p.second;
        for(int i = 0;i<4;i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(valid(X,Y)==true)
            {
                visited[X][Y] = true;
                dst[X][Y] = dst[x][y]+1;
                q.push(MP(X,Y));
                if(s[X][Y] == 'a' or s[X][Y] == 'b' or s[X][Y] == 'c')
                {
                    mx = max(mx,dst[X][Y]);
                }
            }
        }
    }
    return mx;
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int tst,cas = 0;
      sc1i(tst);
      while(tst--)
      {
          sc2i(r,c);
          for(int i = 0 ; i < 25;i++){
            s[i].clear();
          }
          for(int i = 0 ;i < r;i++){
            cin>>s[i];
          }
          int x,y;bool t = false;
          for(int i = 0 ; i < r;i++){
              for(int j = 0 ; j < c;j++){
                if(s[i][j] == 'h'){
                    x = i;y = j;t = true;break;
                }
              }
              if(t)break;
          }
          int ans = bfs(x,y);
          pf("Case %d: %d\n",++cas,ans);
      }
      return 0;
}
