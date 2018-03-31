#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int dx[10000005];
int dy[10000005];

void init()
{
        int i,j,k=0,l=0;
        for(i=1;;i++)
        {
                if(i%2==0)
                {
                        for(j=1;j<=i;j++)
                        {
                                dy[++k]=j;
                        }
                        for(j=i-1;j>=1;j--)
                        {
                                dy[++k]=j;
                        }
                }
                else
                {
                        for(j=1;j<=i;j++)
                        {
                                dx[++l]=j;
                        }
                        for(j=i-1;j>=1;j--)
                        {
                                dx[++l]=j;
                        }
                }
                if(k>=10000003 && l>=10000003)break;
        }
}

int main()
{
        int n,i=1;
        init();
        while(sc("%d",&n)==1)
        {
                pf("TERM %d IS %d/%d\n",n,dx[n],dy[n]);
        }
        return 0;
}
