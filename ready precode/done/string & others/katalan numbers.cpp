#include<bits/stdc++.h>
using namespace std;

int arr[1005][1005] = {{0}};

int mod = 1000000;

void catalan()
{
    int i,j;
    for(i=0;i<1005;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0)
                arr[i][j]=1;
            else
                arr[i][j]=(arr[i][j-1]+arr[i-1][j])%mod;
        }
    }
}

int main()
{
    catalan();
    int t;
    scanf("%d",&t);
    while(t)
    {
        printf("%d\n",arr[t][t]);
        scanf("%d",&t);
    }
    return 0;
}
