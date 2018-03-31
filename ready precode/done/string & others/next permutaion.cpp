#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int main()
{
    char a[500];
    while(sc("%s",&a))
    {
        while(next_permutation(a,a+strlen(a)))//array and desired length
        {
            pf("%s\n",a);
        }
    }
    return 0;
}
