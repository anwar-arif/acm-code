#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define LL long long
#define pb push_back

int main()
{
        int N,lastval,i,lim,r,c,j,k,a[150][150];
        while(sc("%d",&N) == 1)
        {
                a[1][1] = 1;
                a[N][N] = N * N;
                lastval = 1;
                for(i = 2; i <= N; i++)
                {
                        lim = lastval + i;
                        r = 1; c = i;
                        for(j = lastval+1; j <= lim; j++)
                        {
                                a[r][c] = j;
                                ++r;
                                --c;
                        }
                        lastval = lim;
                }

                k = N - 1;

                for(i = 2; i < N; i++)
                {
                        lim = lastval + k;
                        r = i; c = N;
                        for(j = lastval + 1; j <= lim; j++)
                        {
                                a[r][c] = j;
                                ++r;
                                --c;
                        }
                        --k;
                        lastval = lim;
                }
                for(i = 1;i <= N;i++)
                {
                        for(j = 1;j <= N;j++)
                        {
                                pf("%d ",a[i][N-j+1]);
                        }
                        pf("\n");
                }
        }
        return 0;
}
