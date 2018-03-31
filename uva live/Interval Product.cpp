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

#define SIZ 1000000+5

struct seg
{
    int neg,pos,zero;
}tree[SIZ*3];

void build(int node,int b,int e)
{
    if(b == e)
    {
        int x;
        sc1i(x);
        tree[node].pos = x > 0 ? 1 : 0;
        tree[node].neg = x < 0 ? 1 : 0;
        tree[node].zero = (x == 0) ? 1 : 0;
        return;
    }
    int lft,rt,mid;
    lft = node << 1;
    rt = lft + 1;
    mid = (b+e) >> 1;

    build(lft,b,mid);
    build(rt,mid+1,e);

    tree[node].neg = tree[lft].neg + tree[rt].neg;
    tree[node].pos = tree[lft].pos + tree[rt].pos;
    tree[node].zero = tree[lft].zero + tree[rt].zero;
    return;
}

void update(int node,int b,int e,int indx,int val)
{
    if(b > indx or e < indx)return;
    if(b >= indx and e <= indx)
    {
        tree[node].pos = val > 0 ? 1 : 0;
        tree[node].neg = val < 0 ? 1 : 0;
        tree[node].zero = (val == 0) ? 1 : 0;
        return;
    }
    int lft,rt,mid;
    lft = node << 1;
    rt = lft + 1;
    mid = (b + e) >> 1;
    update(lft,b,mid,indx,val);
    update(rt,mid+1,e,indx,val);

    tree[node].neg = tree[lft].neg + tree[rt].neg;
    tree[node].pos = tree[lft].pos + tree[rt].pos;
    tree[node].zero = tree[lft].zero + tree[rt].zero;
    return;
}

pair<int,pair<int,int> > query(int node,int b,int e,int i,int j)
{
    if(b > j or e < i)return MP(0,MP(0,0));
    if(b >= i and e <= j)
    {
        int a,bb,c;
        a = tree[node].neg;
        bb = tree[node].pos;
        c = tree[node].zero;
        return MP(a,MP(bb,c));
    }
    int lft,rt,mid;
    lft = node << 1;
    rt = lft + 1;
    mid = (b+e) >> 1;
    pair<int,pair<int,int> > p;
    p = query(lft,b,mid,i,j);

    int a,bb,c;
    a = p.first;
    bb = p.second.first;
    c = p.second.second;

    p = query(rt,mid+1,e,i,j);
    a += p.first;
    b += p.second.first;
    c += p.second.second;
    return MP(a,MP(b,c));
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int n,q;
      while(sc2i(n,q) != EOF)
      {
          build(1,1,n);
          getchar();
          char ch;
          string s = "";
          while(q--)
          {
              sc("%c",&ch);
              if(ch == 'C')
              {
                  int indx,val;
                  sc2i(indx,val);
                  update(1,1,n,indx,val);
              }
              else
              {
                  int x,y;
                  sc2i(x,y);
                  pair<int,pair<int,int> > p;
                  p = query(1,1,n,x,y);
                  int a = p.first;
                  int b = p.second.first;
                  int c = p.second.second;
                  if(c){
                        s+="0";
                  }
                  else if(a%2 == 1){
                        s+="-";
                  }
                  else {
                        s+="+";
                  }
              }
              getchar();
          }
          cout<<s;
          pf("\n");
      }
      return 0;
}
