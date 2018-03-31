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
int dx[]= {0,0,1,-1};//4 side move
int dy[]= {-1,1,0,0};//4 side move
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

//ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

//int on(int n,int pos){return n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = 300 + 10 ;

const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 60006;

int src, snk, nNode, nEdge;

int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];

int flow[MAXE], cap[MAXE], Next[MAXE], to[MAXE];
int x[MAXN] , y[MAXN] , p[MAXN] , jmp[MAXN] , n;
double D ;

inline void init(int _src, int _snk, int _n) {

    src = _src, snk = _snk, nNode = _n, nEdge = 0;

    mem(fin,-1);
}

inline void add(int u, int v, int c) {

    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, Next[nEdge] = fin[u], fin[u] = nEdge++;

    to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0, Next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    int st, en, i, u, v;
    mem(dist,-1);

    dist[src] = st = en = 0;
    Q[en++] = src;

    while(st < en) {
        u = Q[st++];

        for(i=fin[u]; i>=0; i=Next[i]) {

            v = to[i];

            if(flow[i] < cap[i] && dist[v]==-1) {

                dist[v] = dist[u]+1;

                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {

    if(u==snk) return fl;

    for(int &e=pro[u], v, df; e>=0; e=Next[e]) {

        v = to[e];

        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {

            df = dfs(v, min(cap[e]-flow[e], fl));

            if(df>0) {

                flow[e] += df;
                flow[e^1] -= df;

                return df;
            }
        }
    }
    return 0;
}

ll dinitz() {

    ll ret = 0;
    int df;

    while(bfs()) {

        for(int i=0; i<=nNode; i++) pro[i] = fin[i];

        while(true) {

            df = dfs(src, INF);

            if(df) ret += (ll)df;

            else break;
        }
    }
    return ret;
}

bool can(int i , int j){
    return ( (sqr(x[i] - x[j]) + sqr(y[i] - y[j])) <= sqr(D) ) ;
}

void make_graph(){
    rep( i , 1 , n ){

        add( 0 , i , p[i] ) ;
        add( i , 0 , p[i]);

        add( i , i+n , jmp[i]);
        add( i+n , i , jmp[i]);

        rep( j , i+1 , n ){
            if(can( i , j )){
                add( i+n , j , INF);
                add( j+n , i , INF);
            }
        }
    }
}

int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" , stdin);
//    #endif
    int tst , cas = 0 ;
    sc1i(tst) ;
    while(tst--){
        sc("%d %lf",&n , &D) ;
        ll tot = 0 , cnt = 0 ;
        rep( i , 1,  n ){
            sc4i(x[i] , y[i] , p[i] , jmp[i]) ;
            tot += p[i] ;
        }
        pf("Case %d:",++cas);
        rep( i , 1 , n ){

            init( 0 , i , n+n+10 );
            make_graph();

            ll x = dinitz() ;

            if(x >= tot){
                pf(" %d",i-1);
                ++cnt ;
            }
        }
        if(cnt == 0)pf(" -1");
        pf("\n");
    }
    return 0;
}

