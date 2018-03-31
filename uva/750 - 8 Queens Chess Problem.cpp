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
#define ppcnt(a) __builtin_popcount(a)

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

//ll BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}

//void on(int &n,int pos){ n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}

int taken[10][10];
int N = 8;

void on(int r,int c)
{
    int i,j;
    ++taken[r][c];
    for(i = c+1;i<=N;i++){++taken[r][i];}//1
    for(i = c-1;i>=1;i--){++taken[r][i];}//2
    for(i = r-1;i>=1;i--){++taken[i][c];}//3
    for(i = r+1;i<=N;i++){++taken[i][c];}//4
    for(i = r-1,j=c+1;i>=1 and j<=N;i--,j++){++taken[i][j];}//5
    for(i = r+1,j=c-1;i<=N and j>=1;i++,j--){++taken[i][j];}//6
    for(i = r-1,j=c-1;i>=1 and j>=1;i--,j--){++taken[i][j];}//7
    for(i = r+1,j=c+1;i<=N and j<=N;i++,j++){++taken[i][j];}//8
}

void off(int r,int c)
{
    int i,j;
    --taken[r][c];
    for(i = c+1;i<=N;i++){--taken[r][i];}//1
    for(i = c-1;i>=1;i--){--taken[r][i];}//2
    for(i = r-1;i>=1;i--){--taken[i][c];}//3
    for(i = r+1;i<=N;i++){--taken[i][c];}//4
    for(i = r-1,j=c+1;i>=1 and j<=N;i--,j++){--taken[i][j];}//5
    for(i = r+1,j=c-1;i<=N and j>=1;i++,j--){--taken[i][j];}//6
    for(i = r-1,j=c-1;i>=1 and j>=1;i--,j--){--taken[i][j];}//7
    for(i = r+1,j=c+1;i<=N and j<=N;i++,j++){--taken[i][j];}//8
}

int k,R,C;
vector<int>v;

void rec(int c)
{
    int len = SZ(v);
    if(len==8){
        pf("%2d     ",++k);
        for(int i = 0 ; i< len;i++){
            pf(" %d",v[i]);
        }
        pf("\n");
        return;
    }
    if(c==C){
        v.pb(R);
        on(R,C);
        rec(c+1);
        off(R,C);
        v.pop_back();
    }
    else
    {
        for(int i = 1;i<=N;i++){
            if(taken[i][c]<=0){
                on(i,c);
                v.pb(i);
                rec(c+1);
                off(i,c);
                v.pop_back();
            }
        }
    }
}

void init()
{
    v.clear();
    for(int i = 0 ; i<=N;i++){
        for(int j = 0 ;j<=N;j++){
            taken[i][j] = 0;
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
        sc2i(R,C);
        k = 0;
        init();
        on(R,C);
        if(cas)pf("\n");
        pf("SOLN       COLUMN\n");
        pf(" #      1 2 3 4 5 6 7 8\n\n");
        rec(1);
        ++cas;
      }
      return 0;
}
