#include <bits/stdc++.h>

using namespace std ;

#define NAZIM
#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 100000
#define sz 1000000
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

map<int,int>mymap ;
int arra[2] = {4,7} ;
int l , a , b ;

void rec(int sum)
{
    if(sum>a && sum<b)
    {
        mymap[sum] = ++l ;
        return;
    }

    int as = 0 ;

    for(int i=0 ; i<2 ; i++)
    {
        as = sum*10 + arra[i] ;
        rec(as);
    }
}

int main()
{
    a = b =1 ;
    l = 0 ;
    int n ;

    for(int i=0 ; i<9 ; i++)
    {
        b = b*10 ;
        rec(0);
        a = a*10 ;
    }

    while(scanf("%d",&n) != EOF)
    {
        cout<<mymap[n]<<endl;
    }

    return 0;
}
