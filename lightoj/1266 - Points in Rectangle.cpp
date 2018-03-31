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

//ll bigmod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

//int on(int n,int pos){return n=n|(1<<pos);}
//void off(int &n,int pos){ n = n & ~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) )://XOR of 1-n numbers

const int N = 1005;

int t[2046][2046] ,n , m ;

void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[vx][vy] = 0;
		else
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
	else {
		int my = (ly + ry) / 2;
		build_y (vx, lx, rx, vy*2, ly, my);
		build_y (vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}

void build_x (int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x (vx*2, lx, mx);
		build_x (vx*2+1, mx+1, rx);
	}
	build_y (vx, lx, rx, 1, 0, m-1);
}

void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = new_val;
		else
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y (vx, lx, rx, vy*2, ly, my, x, y, new_val);
		else
			update_y (vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}

void update_x (int vx, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x (vx*2, lx, mx, x, y, new_val);
		else
			update_x (vx*2+1, mx+1, rx, x, y, new_val);
	}
	update_y (vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int sum_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return sum_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
		+ sum_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
}

int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return sum_y (vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return sum_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		+ sum_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
}


int main(){
    n = m = 1003;
    int t,x1,x2,y2,y1,ans,q;
    int tst,cas = 0;
    sc1i(tst);
    while(tst--){
        build_x(1,0,n-1);
        sc1i(q);
        pf("Case %d:\n",++cas);
        while(q--){
            sc1i(t);
            if(!t){
                sc2i(x1,y1);
                update_x(1,0,n-1,x1,y1,1);
            }
            else{
                sc4i(x1,y1,x2,y2);
                int ans = sum_x(1,0,n-1,x1,x2,y1,y2);
                pf("%d\n",ans);
            }
        }
    }
    return 0;
}
