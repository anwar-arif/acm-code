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
#define dbl double

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
#define p_inf INT_MAX
#define n_inf INT_MIN
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

const int N = 4000+5;

int lps[65] , n , k , tst;
char s[15][65] , c[65];

void cal_lps(char pat[]){
    lps[0] = 0;
    int len = strlen(pat);
    int indx = 0;
    for(int i = 1 ; i < len;){
        if(pat[i] == pat[indx]){
            lps[i] = indx + 1;
            i++,indx++;
        }
        else{
            if(indx != 0){
                indx = lps[indx - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool kmp(char text[],char pat[]){
    int len = strlen(text);
    int i = 0 , j = 0 ;
    int pat_len = strlen(pat);
    while(i < len){
        if(text[i] == pat[j]){
            i++,j++;
        }
        if(j == pat_len)return true;
        else if(i < len and pat[j] != text[i]){
            if(j != 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }
    return false;
}

int main()
{
    sc1i(tst);
    while(tst--){
        sc1i(n);
        int now = 0 , mx = 0 , len;
        for(int i = 1; i <= n;i++){
            sc("%s",s[i]);
            len = strlen(s[i]);
            if(len > mx){
                mx = len;now = i;
            }
        }
        bool t = false;
        char ans[205] = "";
        for(int len = mx; len >= 1;len--){
            for(int i = 0 ; i<= mx - len;i++){
                strncpy(c,s[now]+i,len);
                c[len] = '\0';
                cal_lps(c);
                for(k = 1; k <= n;k++){
                    if(k != now){
                        if(!kmp(s[k],c)){
                            --k;
                            break;
                        }
                    }
                }
                if(k == n+1){
                    t = true;
                    if(strcmp(c,ans) < 0 or !strlen(ans)){
                        strncpy(ans,c,strlen(c));
                    }
                }
            }
            if(t)break;
        }
        if(t and strlen(ans) >= 3){
            pf("%s\n",ans);
        }else pf("no significant commonalities\n");
    }
    return 0;
}


