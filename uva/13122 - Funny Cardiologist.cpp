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
#define ull unsigned ll

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
#define sqr(a) ((a)*(a))
#define ppcnt(a) __builtin_popcount(a)
#define cnttz(a) __builtin_ctz(a)
#define cntlz(a) __builtin_clz(a)

#define rep(i,k,n) for(__typeof(n)i = k ; i <= n; i++)
#define rrep(i,k,n) for(__typeof(k)i = k ; i >= n; i--)
#define show(a) cerr <<#a<< " = " << a << endl;

#define wait system("pause")
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

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

const int N = (int)260 + 10;
const double inf = 1e30 ;

struct point {
    double x , y ;
    point(){}
    point( double _x , double _y ) {
        x = _x ; y = _y ;
    }
}arr[N];

double dp[N][N][N] , csum[N] ;
int vis[N][N][N] , cas , n , k ;

double dist( int i , int j ) {
    return sqrt( sqr( arr[i].x - arr[j].x ) + sqr( arr[i].y - arr[j].y ) ) ;
}

double rec( int pos , int last , int cnt ) {
    if( pos == n ) {
        if( cnt == 0 ){
            return dist(last , pos ) + csum[pos] ;
        }
        return inf ;
    }
    if( cnt == 0 ) {
        return dist( last , pos ) + csum[pos] ;
    }
    int &v = vis[pos][last][cnt] ;
    double &ret = dp[pos][last][cnt] ;
    if( v == cas ) return ret ;
    v = cas ;
    ret = inf ;
    ret = min( ret , dist( last , pos) + rec( pos+1 , pos , cnt ) ) ;
    ret = min( ret , rec( pos+1 , last , cnt-1 ) ) ;
    return ret ;
}

int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" , stdin);
//    #endif
    mem( vis , 0 ) ;
    cas = 0 ;
    double x , y ;
    while( sc2i( n , k ) != EOF ) {
        ++cas ;
        for( int i = 1 ; i <= n ; i++) {
            sc("%lf %lf" , &x , &y ) ;
            arr[i] = point( x , y ) ;
        }
        csum[n] = 0.0 ;
        for( int i = n-1 ; i >= 1 ; i-- ) {
            csum[i] = dist( i , i+1 ) + csum[i+1] ;
        }
        double ans = rec( 2 , 1 , k ) ;
        pf("%0.3lf\n" , ans ) ;
    }
    return 0;
}
