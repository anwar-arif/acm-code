#include <bits/stdc++.h>
using namespace std;

#define pf            printf
#define sc            scanf
#define pb            push_back
#define LL            long long
#define fill(a,x)     memset(a,x,sizeof(a))
#define MIN3(a,b,c)   min(a,min(b,c))
#define MAX3(a,b,c)   max(a,max(b,c))
#define PI            acos(-1.0)
#define INF           0xfffffff
#define mx            1050
#define on(x)         (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)       marked[x/64] |= (1<<((x%64)/2))

LL int prime [50000];
LL int marked[mx/64 + 2];
LL int a[1005],ans[1005];

void sieve()
{
    for (LL int i = 3; i * i < mx; i += 2)
        {
            if (!on(i))
            {
                 for (LL int j = i * i; j <= mx; j += i + i)
                 {
                     mark(j);
                 }
            }
        }
}

bool isprime(LL int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

void siv()
{
        LL int i,p=0;
        for(i = 2; i <= mx; i++)
        {
                if(isprime(i))prime[++p] = i;
        }
        //pf("p is %lld\np[%lld] is %lld\n",p,p,prime[p]);
}

LL int divisor(LL int n)
{
        LL int sum,i,cnt;
        sum = 1;
        for(i = 1; prime[i] * prime[i] <= n ; i++)
        {
                if(n % prime[i] == 0)
                {
                        cnt = 0;
                        while(n % prime[i] == 0)
                        {
                                ++cnt;
                                n = n / prime[i];
                        }
                        sum = sum * (cnt + 1);
                }
        }
        if( n > 1) sum = sum * 2;

        return sum;
}

bool cmp(LL int u,LL int v)
{
        if(a[u] == a[v]) return u > v;
        else return a[u]< a[v];
}

int main()
{
        LL int i,tst,x;
        sieve();
        siv();
        for(i = 1 ;i <= 1000; i++)
        {
                x = divisor(i);
               a[i] = x;
               ans[i] = i;
        }
        sort(ans+1,ans+1001,cmp);

        sc("%lld",&tst);
        for(i = 1; i <= tst; i++)
        {
                sc("%lld",&x);
                pf("Case %lld: %lld\n",i,ans[x]);
        }
        return 0;
}
