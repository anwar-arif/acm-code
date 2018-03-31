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
#define repll(i,x,n) for(ll i = x; i <= n;i++)
#define rrepll(i,x,n) for(ll i = x; i >= n;i--)
#define repi(i,x,n) for(int i = x; i <= n;i++)
#define rrepi(i,x,n) for(int i = x; i >= n;i--)

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

const int N = 100005;
const int M = 53;

int id;

struct trie{
    int cnt , child[53];
}tree[N];

int new_node(){
    for(int i = 0 ; i < M ; i++)tree[id].child[i] = 0;
    tree[id].cnt = 0;
    return id++;
}

int get(char c){
    if(c >= 'A' && c <= 'Z')return (26 + (c - 'A'));
    return (c - 'a');
}

void add(char s[],int len){
    int cur = 0 ;
    for(int i = 0 ; i < len;i++){
        int typ = get(s[i]);
        if(tree[cur].child[typ] == 0){
            tree[cur].child[typ] = new_node();
        }
        cur = tree[cur].child[typ];
    }
    ++tree[cur].cnt;
}

int f(char s[],int len){
    int cur = 0 ;
    if(len == 0)return 1;
    for(int i = 0 ; i < len;i++){
        int typ = get(s[i]);
        if(tree[cur].child[typ] == 0)return 0;
        cur = tree[cur].child[typ];
    }
    return tree[cur].cnt;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //Read;
    //Write;
    #endif
    char s[110] , line[N];
    ll ans;
    int tst,cas = 0,n;
    int len , l , indx;
    sc1i(tst);
    while(tst--){
        sc1i(n);
        id = 0 ;
        new_node();
        getchar();
        while(n--){
            gets(s);
            len = strlen(s);
            if(len > 2)sort(s+1,s+len-1);
            add(s,len);
        }
        sc1i(n);
        getchar();
        pf("Case %d:\n",++cas);
        while(n--){
            gets(line);
            len = strlen(line);
            ans = 1;indx = 0 ;
            for(int i = 0 ; i < len;i++){
                if(line[i] == ' '){
                    s[indx++] = '\0';
                    l = strlen(s);
                    if(l > 2)sort(s+1,s+l-1);
                    if(l > 0)ans *= (ll)f(s,l);
                    indx = 0 ;
                }
                else s[indx++] = line[i];
            }
            s[indx++] = '\0';
            l = strlen(s);
            if(l > 2)sort(s+1,s+l-1);
            if(l > 0)ans *= (ll)f(s,l);
            pf("%lld\n",ans);
        }
    }
    return 0;
}
