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

const int N = 100000+5;
ll k , n;
ll mod = 10007;

struct matrix{
    ll v[5][5] , row , col;
};


matrix multiply(matrix a, matrix b) {

  matrix r;

  r.row = a.row;
  r.col = b.col;

  for (ll i = 1; i <= r.row; i++) {

    for (ll j = 1; j <= r.col; j++) {

      ll sum = 0;

      for (ll k = 1; k <= a.col;  k++) {

        sum += a.v[i][k] * b.v[k][j];
        sum %= mod;
      }
      sum += mod;
      sum %= mod;
      r.v[i][j] = sum;
    }

  }
  return r;
}

/// returns mat^p
matrix power(matrix mat, ll p) {

  if (p == 1) return mat;

  if (p % 2 == 1){

      matrix ret;
      ret = multiply(mat, power(mat, p - 1));
      return ret;
  }
  else{
      matrix ret = power(mat, p / 2);
      ret = multiply(ret, ret);
      return ret;
  }
}

int main(){
    ll tst,cas = 0 , n , a, b,c;
    sc1ll(tst);
    while(tst--){
        sc4ll(n,a,b,c);

        matrix mat;
        mat.row = mat.col = 4;

        mat.v[1][1] = a;mat.v[1][2] = 0; mat.v[1][3] = b; mat.v[1][4] = 1;

        for(ll i = 2; i < mat.col;i++){
            for(ll j = 1;j <= mat.col;j++){
                mat.v[i][j] = (j+1 == i) ? 1 : 0;
            }
        }

        for(ll i = 1; i <= mat.col;i++){
            mat.v[mat.col][i] = (i == mat.col) ? 1 : 0;
        }

        matrix b;
        b.col = 1; b.row = 4;
        for(ll i = 1; i<= b.row;i++){
            b.v[i][1] = (i == b.row) ? c : 0;
        }
        pf("Case %lld: ",++cas);
        if(n <= 2){
            pf("0\n");
        }
        else{
            mat = power(mat , n - 2);
            matrix res = multiply(mat , b);
            ll ans = res.v[1][1];
            ans += mod;
            ans %= mod;
            pf("%lld\n",ans);
        }
    }
    return 0;
}
