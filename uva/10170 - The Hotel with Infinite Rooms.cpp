#include <bits/stdc++.h>
using namespace std;
int main()
{
        long long int n,s,d,i;
        while(scanf("%lld%lld",&s,&d)==2)
        {
                n=0;
                for(i=s;;i++)
                {
                        n=n+i;
                        if(n>d || n==d){printf("%lld\n",i);break;}
                }
        }
        return 0;
}
