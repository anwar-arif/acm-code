#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long
#define mx 214748
#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

LL int prime [47010];
LL int marked[mx/64 + 2];
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
        //pf("p si %lld\n",p);
}

int main()
{
        LL int n,i,x;
        sieve();
        siv();
        sc("%lld",&n);
        for(i=1;i<=n;i++)
        {
                sc("%lld",&x);
                pf("%lld\n",prime[x]);
        }
        return 0;
}
