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
#define PI acos(-1.0)
#define mem(a,x) memset(a,x,sizeof(a))
#define all(v) v.begin(),v.end()
#define SZ(a) (int)a.size()
#define MP make_pair
#define sqr(a) ((a)*(a))
#define ppcnt(a) __builtin_popcount(a)
#define cnttz(a) __builtin_ctz(a)
#define cntlz(a) __builtin_clz(a)

#define rep(i,k,n) for(__typeof(n)i = k ; i <= n; i++)
#define rrep(i,k,n) for(__typeof(k)i = k ; i >= n; i--)
#define show(a) cerr <<#a<< " = " << a << endl;

#define wait system("pause")
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

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<< v <<" ";
        return *this;
    }
}dbg;
#define deb(args...) {dbg,args; cerr<<endl;}

void make_unique(vector<int> &a){ sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); }

ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

//int on(int n,int pos){return n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = 50000 + 10 ;
const double EPS = 1e-9 ;

struct data{
    double b , h , w , d ;
    data(){}
    data(double _b , double _h , double _w , double _d){
        b = _b ; h = _h , w = _w , d = _d ;
    }
}arr[N];

double v ;
int n ;

bool can(double lim){
    double s = 0 , x , b , h , d , w;
    rep( i , 1 , n ){
        b = arr[i].b ; h = arr[i].h ; d = arr[i].d ; w = arr[i].w ;
        if( lim - (b + h) > EPS ) s += (h * w * d) ;
        else if(lim - b > EPS) s += (lim - b) * w * d ;
    }
    return (v - s) < EPS;
}

int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" , stdin);
//    #endif
    int tst , cas = 0 ;
    double b , h , w , d ;
    sc1i(tst) ;
    while(tst--){
        sc1i(n);
        double tot = 0.0 ;
        rep( i , 1 , n ){
            sc("%lf%lf%lf%lf",&b , &h , &w , &d);
            arr[i] = data(b , h , w , d);
            tot += (h * w * d);
        }
        sc("%lf",&v);
        if(v > tot)pf("OVERFLOW\n");
        else{
            double lo = 0.0 , hi = 5e+9 , mid , ans;
            while(hi - lo > EPS){
                mid = (lo + hi) / 2.0 ;
                if( can(mid) ){
                    ans = mid ;
                    hi = mid;
                }else lo = mid;
            }
            pf("%0.2lf\n",ans);
        }
    }
    return 0;
}

