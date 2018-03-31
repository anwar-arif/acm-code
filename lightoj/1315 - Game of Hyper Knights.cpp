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

//template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}//N^P
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}//gcd(a,b)

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<< v <<" ";
        return *this;
    }
}dbg;
#define deb(args...) {dbg,args; cerr<<endl;}

//void make_unique(vector<int> &a){ sort(a.begin(), a.end());
//    a.erase(unique(a.begin(), a.end()), a.end()); }

ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0){if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

//int on(int n,int pos){return n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = 500 + 5;

const int dx[] = {-3, -2, -2, -1, -1, 1};
const int dy[] = {-1, -1, 1, -3, -2, -2};

int gr[N][N] ;

bool valid(int x , int y){
    return(x >= 0 && y >= 0);
}

void rec(int i , int j){
    if(gr[i][j] != -1)return;
    vector<int>v;
    v.clear();
    int x, y;
    for(int k = 0 ; k < 6;k++){
        x = i + dx[k];
        y = j + dy[k];
        if(valid(x , y)){
            rec(x , y);
            v.pb(gr[x][y]);
        }
    }
    int len = SZ(v);
    sort(all(v));
    if(len == 0 || v[0] > 0){
        gr[i][j] = 0;
        return;
    }
    for(int k = 1 ;k < len;k++){
        if(v[k] > v[k-1]+1){
            gr[i][j] = v[k-1]+1;
            return;
        }
    }
    gr[i][j] = v[len-1]+1;
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    mem(gr , -1);
    rep(i , 0 , N-2){
        rep(j , 0 , N-2){
            if(gr[i][j] == -1)rec(i,j);
        }
    }
    int tst , cas = 0 ;
    sc1i(tst);
    while(tst--){
        int n , x , y;
        sc1i(n);
        int xr = 0;
        while(n--){
            sc2i(x,y);
            xr ^= gr[x][y];
        }
        pf("Case %d: %s\n",++cas , xr>0?"Alice":"Bob");
    }
    return 0;
}
