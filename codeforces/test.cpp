#include <bits/stdc++.h>
using namespace std;

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

#define show(a) cerr <<#a<< " = " << a << endl;

#define wait system("pause")
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {1,0-1,0};//4 side move
//int dy[]= {0,1,0,-1};//4 side move
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

//ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}
//ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

int on(int n,int pos){return n=n|(1<<pos);}
int off(int n,int pos){return n = n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}

const long long mod = 998244353;

inline void add(long long &a, long long b) {
  a += b ;
  if(a >= mod) a -= mod ;
}

inline void sub(long long &a, long long b) {
  a -= b ;
  if(a < 0) a += mod ;
}

inline long long mul(long long a, long long b) {
  return ((long long) a * b % mod) ;
}

inline long long modpow(long long b, long long p) {
  long long res = 1 ;
  while(p > 0) {
    if((p & 1LL)) {
      res = mul(res, b) ;
    }
    b = mul(b, b) ;
    p >>= 1LL ;
  }
  return res ;
}
/*(x)^(-1)*/
inline long long modinv(long long b) {
    return modpow(b, mod - 2) ;
}

const int N = (int)1e5 + 10;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    #endif

    return 0;
}
