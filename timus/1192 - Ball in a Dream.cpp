#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define sc1ll(a) sc("%I64d",&a)
#define sc2ll(a,b) sc("%I64d%I64d",&a,&b)
#define sc3ll(a,b,c) sc("%I64d%I64d%I64d",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define pi acos(-1)
#define mod 100000007
#define inf 1<<28
#define mx 10001

double a,k;

double rec(double v)
{
        if(v < 1e-3)return 0;
        double sum = v*v*sin(2*a)/10;
        return sum+rec(v/sqrt(k));
}

int main()
{
        double v;
        while(sc("%lf%lf%lf",&v,&a,&k) == 3){
                a = (pi*a)/180;
                pf("%0.2lf\n",rec(v));
        }
        return 0;
}
