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

LL int sum(LL int n)
{
        int i,sum,s,p;

        sum = 1;
        for(i = 1 ;prime[i] * prime[i] <= n ; i++)
        {
                if(n % prime[i] == 0)
                {
                        p = 1 ;
                        while(n % prime[i] == 0)
                        {
                                n = n / prime[i];
                                p = p * prime[i];
                        }
                        p = p * prime[i];
                        s = (p - 1)/ (prime[i] - 1);
                        sum = sum * s;
                }
        }

        if(n > 1)
        {
                p = n * n;
                s = (p - 1) / (n - 1);
                sum = sum * s;
        }
        return sum;
}

int main()
{
        LL int a,b,res,s,i;
        double mn,ans;

//        clock_t beginn, endd;
//        double time_spent;
//        beginn = clock();

        sieve();
        siv();
        while(sc("%lld%lld",&a,&b) == 2)
        {
                //if(a == 0 || b ==0)break;
                if(a > b){swap(a,b);}

                mn = 100000.0;

                for(i = a; i <= b; i++)
                {
                        s = sum(i);
                        ans = double(s - i) / (double)i;
                        if(ans<mn)
                        {
                                mn = ans;
                                res = i;
                        }
                }

                pf("ans is %lld\n",res);
        }
//        endd = clock();
//        time_spent = (double)(endd - beginn) / CLOCKS_PER_SEC;
//        printf("%lf\n",time_spent);
        return 0;
}
