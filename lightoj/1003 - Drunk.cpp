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
#define SIZ 10000

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


int main()
{
      int tst,cas,edge,k,cnt,u,v,i;
      sc1i(tst);
      cas = 0 ;
      while(tst--)
      {
          sc1i(edge);
          map<string,int>m;
          map<pair<int,int>,int>connected;
          vector<int>g[10005];
          int deg[10005];
          k = 0;
          string s1,s2;
          mem(deg,0);
          while(edge--){
          cin>>s1>>s2;
          if(m[s1] == 0)
          {
              m[s1] = ++k;
          }
          if(m[s2] == 0)
          {
              m[s2] = ++k;
          }
          g[m[s1]].pb(m[s2]);
          connected[MP(m[s1],m[s2])] = 1;
          ++deg[m[s2]];
       }
       cnt = 0;
       queue<int>q;
       for(i = 1; i<= k;i++)
       {
           if(deg[i] == 0)
           {
               q.push(i);
               ++cnt;
           }
       }
       while(!q.empty())
       {
           u = q.front();q.pop();
           for(i = 0 ; i < g[u].size();i++)
           {
               v = g[u][i];
               if(connected[MP(u,v)] == 1)
               {
                   connected[MP(u,v)] = 0;
                   --deg[v];
                   if(deg[v] == 0)
                   {
                       q.push(v);
                       ++cnt;
                   }
               }
           }
       }
       if(cnt == k)
       {
           pf("Case %d: Yes\n",++cas);
       }
       else
       {
           pf("Case %d: No\n",++cas);
       }
    }
      return 0;
}
