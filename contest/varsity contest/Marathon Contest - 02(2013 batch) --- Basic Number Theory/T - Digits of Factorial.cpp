#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <math.h>
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

long long int j,tst,ans;
long n,b,i;
double a[1000009];

int main()
{
        for(i=1;i<=1000002;i++)
        {
                a[i]=log((i))+a[i-1];
        }
        scanf("%lld",&tst);
        for(j=1;j<=tst;j++)
        {
                scanf("%ld%ld",&n,&b);
                ans=a[n]/log(double(b));
                printf("Case %lld: %ld\n",j,ans+1);
        }
        return 0;
}

