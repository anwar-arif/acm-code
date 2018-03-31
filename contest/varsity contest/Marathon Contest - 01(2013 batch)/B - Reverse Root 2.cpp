#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        unsigned long long int n;
        LL siz,i;
        double x;
        vector<double > v;

        while(sc("%llu",&n) !=EOF)
        {
                x = sqrt(double(n*1.0));
                v.pb(x);
        }
        siz = (int)v.size();
        for(i = siz - 1; i>=0; i--)
        {
                pf("%0.4lf\n",v[i]);
        }
        return 0;
}
