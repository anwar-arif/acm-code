#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n,m,ans;
    scanf("%lf%lf",&n,&m);

    ans=0;
    for(double i=1;i<=n;i++)
    {
        ans+=((m-i+1)/m);

    }
    printf("%.9f\n",ans);
}
