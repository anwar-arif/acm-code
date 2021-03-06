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

#define SIZ 10000+5


int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int n;
      while(sc1i(n) != EOF)
      {
          int sq = (int)sqrt(n);
          int s = n/sq;

          vector<vector<int> >act,inp;

          for(int i = 0 ; i<s;i++)
          {
              vector<int>temp;
              int x;
              for(int j = 0;j < sq;j++)
              {
                  sc1i(x);
                  temp.pb(x);
              }
              act.pb(temp);
              inp.pb(temp);
          }
          vector<int>temp;
          int x;
          for(int i = s*sq;i < n;i++)
          {
              sc1i(x);
              temp.pb(x);
          }
          if(s*sq != n)
          {
              act.pb(temp);
              inp.pb(temp);
          }
          int siz = inp.size();
          for(int i = 0  ;i < siz;i++)
          {
              sort(inp[i].begin(),inp[i].end());
          }
          int q;
          sc1i(q);
          getchar();
          while(q--)
          {
              char ch;
              sc("%c",&ch);
              if(ch == 'Q')
              {
                  int st,en;
                  sc2i(st,en);
                  --st;--en;
                  if(st == en){
                      pf("0\n");continue;
                  }
                  int beg = st/sq;
                  int endd = en/sq;

                  st -= beg*sq;
                  en -= endd*sq;

                  if(beg == endd)
                  {
                      int mx1 = 0 , mx2 = 0;

                      for(int i = st;i <= en;i++)
                      {
                          int xx = inp[beg][i];
                          if(xx > mx1 and xx > mx2){
                                mx2 = mx1;mx1 = xx;
                          }
                          else if(xx > mx2 and xx <= mx1)mx2 = xx;
                      }
                      int ans = mx1 + mx2;
//                      deb("mx1",mx1,"mx2",mx2);

                      pf("%d\n",ans);
                  }
                  else
                  {
                      int mx1 = 0 , mx2 = 0;

                      int len  = act[beg].size();

                      for(int i = st;i<len;i++)
                      {
                          int xx = act[beg][i];

                          if(xx > mx1 and xx > mx2){
                                mx2 = mx1;mx1 = xx;
                          }
                          else if(xx > mx2 and xx <= mx1)mx2 = xx;
                      }
                      for(int i = 0;i <= en;i++)
                      {
                          int xx = act[endd][i];

                          if(xx > mx1 and xx > mx2){
                                mx2 = mx1;mx1 = xx;
                          }
                          else if(xx > mx2 and xx <= mx1)mx2 = xx;
                      }

                      len = inp[beg+1].size();

                      for(int i = beg+1;i<endd;i++)
                      {
                          int xx = inp[i][len-1];
                          if(xx > mx1 and xx > mx2){
                                mx2 = mx1;mx1 = xx;
                          }
                          else if(xx > mx2 and xx <= mx1)mx2 = xx;

                          xx = inp[i][len-2];
                          if(xx > mx1 and xx > mx2){
                                mx2 = mx1;mx1 = xx;
                          }
                          else if(xx > mx2 and xx <= mx1)mx2 = xx;
                      }
                      int ans = 0;
                      ans += mx1 + mx2;
//                      deb("mx1",mx1,"mx2",mx2);
                      pf("%d\n",ans);
                  }
              }
              else
              {
                  int val,st;
                  sc2i(st,val);
                  --st;
                  int beg = st/sq;
                  st -= beg*sq;
                  act[beg][st] = val;
                  inp[beg] = act[beg];
                  sort(inp[beg].begin(),inp[beg].end());
              }
              getchar();
          }
      }
      return 0;
}
