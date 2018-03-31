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
int dx[]= {1,1,0,-1,-1,-1,0,1};//8 side move
int dy[]= {0,1,1,1,0,-1,-1,-1};//8 side move
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

void make_unique(vector<string> &a){ sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); }
ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

//int on(int n,int pos){return n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
////N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = (int)100 + 10;

vector< int > g[N] ;

struct edge{
    int u ; double w ;
    edge(){}
    edge( int _u , double _w ){
        u = _u ; w = _w ;
    }
    bool operator < (const edge & p )const {
        return w < p.w ;
    }
};

int par[N] , n , m ;
double level[N] , c[N][N] , k , s ;

double dij( int s , int t ) {
    priority_queue< edge > q ;
    q.push( edge( s , 1.0) ) ;
    level[s] = 1.0 ;
    par[s] = -1 ;
    while( !q.empty() ) {
        edge top = q.top() ; q.pop() ;
        int u = top.u ;
        int len = SZ( g[u] ) ;
        rep( i , 0 , len-1 ) {
            int v = g[u][i] ;
            if( level[v] < level[u]*c[u][v] ) {
                level[v] = level[u]*c[u][v] ;
                par[v] = u ;
                q.push( edge( v , level[v] ) ) ;
            }
        }
    }
}

void reset() {
    rep( i , 0 , N-2 ) {
        g[i].clear() ;
        level[i] = 0.0 ;
    }
}

int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" , stdin);
//    #endif
    int tst , cas = 0 , u , v ;
    double p ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        reset() ;
        scanf("%d %d %lf %lf " , &n , &m , &s , &k ) ;
        rep( i , 1 , m ) {
            sc("%d %d %lf" , &u , &v , &p ) ;
            g[u].pb(v) ;
            g[v].pb(u) ;
            p /= 100.0;
            c[u][v] = c[v][u] = p ;
        }
        dij( 0 , n-1 ) ;
        p = 1.0 ;
        v = n-1 ;
        while( par[v] != -1 ) {
            u = par[v] ;
            p *= c[u][v] ;
            v = u ;
        }
        pf("Case %d: %0.9f\n" , ++cas , (2.0*k*s) / p ) ;
    }
//   cerr << clock() << " ms" << endl;
    return 0;
}

