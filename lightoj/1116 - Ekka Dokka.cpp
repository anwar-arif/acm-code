#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>
using namespace std;

#define pf printf
#define sc scanf

int main()
{
        long long int tst,i,n,ans;
        sc("%lld",&tst);
        for(i=1;i<=tst;i++)
        {
                sc("%lld",&n);
                if(n & 1)
                {
                        pf("Case %lld: Impossible\n",i);
                }
                else
                {
                        ans=1;
                        while(n%2==0)
                        {
                                ans=ans*2;
                                n=n/2;
                        }
                        pf("Case %lld: %lld %lld\n",i,n,ans);
                }
        }
        return 0;
}
