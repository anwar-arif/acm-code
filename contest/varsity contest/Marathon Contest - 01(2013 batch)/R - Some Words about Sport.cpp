#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int main()
{
        int N,i,j,k,r,c,a[109][109];
        while(sc("%d",&N) == 1)
        {
                for(i = 1; i <= N; i++)
                {
                        for(j = 1; j <= N; j++)
                        {
                                sc("%d", &a[i][j]);
                        }
                }

                for(i = 1; i <= N ;i++)
                {
                        c = 1; r = i ;
                        for(k = 1; k <= i; k++)
                        {
                                pf("%d ",a[r][c]);
                                --r; ++c;
                        }
                }

                for(i = 1; i <= N - 1; i++)
                {
                        r = N; c = i + 1;
                        for(k = 1; k <= N - i; k++)
                        {
                                pf("%d ",a[r][c]);
                                --r; ++c;
                        }
                }
                pf("\n");
        }
        return 0;
}
