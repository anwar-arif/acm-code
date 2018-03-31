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
#define p_inf 999999999
#define n_inf -999999999
#define SIZ 10000+5

#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
/*
int dx[]= {-1,-1,0,0,1,1};
int dy[]= {-1,0,-1,1,0,1};
int dx[]= {0,0,1,-1};//4 side move
int dy[]= {-1,1,0,0};//4 side move
int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
int dx[]={1,1,2,2,-1,-1,-2,-2};//knight move
int dy[]={2,-2,1,-1,2,-2,1,-1};//knight move
*/
template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

//ll BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}

vector<int>v;
vector<int>prime_fact[SIZ+5];
bool ck[SIZ+5];

void prime()
{
    mem(ck,true);
    int i,j;
    for(i = 2; i*i <= SIZ;i++)
    {
        if(ck[i] == true)
        {
            for(j = 2*i;j<=SIZ;j+=i)
            {
                ck[j] = false;
            }
        }
    }
    for(i = 2; i<= SIZ;i++)
    {
        if(ck[i] == true)
        {
            v.pb(i);
        }
    }
}

void fact()
{
    int i,j,len;
    len = (int)v.size();
    for(i = 2; i<= SIZ;i++)
    {
        for(j = 0 ; (j < len);j++)
        {
            if(i % v[j] == 0 and v[j] < i)
            {
                prime_fact[i].pb(v[j]);
            }
        }
    }
}

int bfs(int s,int t)
{
    int level[SIZ+5],i,u,v,len;
    bool visited[SIZ+5];
    mem(visited,false);
    level[s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        u = q.front();q.pop();

        if(u == t)return level[u];
        len = (int)prime_fact[u].size();

        for(i = 0; i < len;i++)
        {
            v = u + prime_fact[u][i];
            if(visited[v] == false and v <= t)
            {
                visited[v] = true;
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
      #ifndef ONLINE_JUDGE
      Read;
      //Write;
      #endif
      prime();
      fact();
      int tst;
      sc1i(tst);
      int cas = 0,s,t,ans;
      while(tst--)
      {
          sc2i(s,t);
          if(s == 1)
          {
              pf("Case %d: -1\n",++cas);
              continue;
          }
          ans = bfs(s,t);
          pf("Case %d: %d\n",++cas,ans);
      }
      return 0;
}

