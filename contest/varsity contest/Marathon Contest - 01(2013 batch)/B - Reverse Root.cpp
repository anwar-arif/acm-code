#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        unsigned LL int i,n;
        double x;
        map<unsigned long long , double>a;
        i=0;
        while(sc("%llu",&n)!=EOF)
        {
                a[++i] = sqrt(double(n) );
        }

        map<unsigned long long,double>::iterator it;

        for(it=a.end();it!=a.begin();it--)
        {
                x=it->second;
                if(it!=a.end())pf("%0.4lf\n",x);
        }
        it=a.begin();
        x=it->second;
        pf("%0.4lf\n",x);
        return 0;
}
