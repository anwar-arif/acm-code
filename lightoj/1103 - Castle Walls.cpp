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

const int N =  2e5 + 5 ;

ll tree[4*N] ;
pair<ll,ll> arr[N] ;

void update(ll node , ll b , ll e , ll i , ll j){
    if( e < i || b > j )return;
    if( b >= i && e <= j){
        tree[node] += 1;
        return;
    }
    ll lft = 2*node , rt = lft + 1  , mid = (b+e)/2;
    update(lft ,b , mid , i , j);
    update(rt , mid+1 , e , i , j);
    tree[node] = tree[lft] + tree[rt];
}

ll query(ll node , ll b , ll e , ll i , ll j){
    if(e < i || b > j)return 0;
    if(b >= i && e <= j)return tree[node];
    ll lft = 2*node , rt = lft + 1  , mid = (b+e)/2;
    return (query(lft , b , mid , i , j) + query(rt , mid+1 , e , i , j));
}

int main()
{
    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
    #endif
    int tst , cas = 0 ;
    ll blue , red , x , y;
    sc1i(tst) ;
    while(tst--){
        sc2ll(blue , red);
        mem(tree , 0);
        rep( i , 1 , blue+red ){
            sc2ll(x , y) ;
            arr[i] = MP(x , y);
        }
        sort(arr+1 , arr+1+blue+red);
        ll ans = 0 ;
        rep( i , 1, blue+red ){
            x = arr[i].first;
            y = arr[i].second;
            ans += query(1 , 1 , blue+red , y , blue+red);
            update(1 , 1 , blue+red , y , y);
        }
        pf("Case %d: %lld\n",++cas , ans);
    }
    return 0;
}

