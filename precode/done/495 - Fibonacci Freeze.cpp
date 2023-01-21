#include <bits/stdc++.h>
using namespace std;

const int r = 5005,c = 1055;

int f[r+5][c+5];

void cal()
{
    f[0][0] = 0;
    f[1][0] = 1;
    int rem,i,j;
    rem = 0;
    for(i = 2; i < r ; i++)
    {
        for(j = 0  ; j  < c; j++)
        {
            f[i][j] = f[ i-1 ][ j ] + f[ i-2 ][ j ] + rem;

            rem = 0;

            if(f[i][j] > 9)
            {
                f[i][j] = f[i][j] % 10;
                rem = 1;
            }
        }
    }
}

int main()
{
    int i,j,ans,n;

    mem(f,0);

    cal();

    while(sc1i(n) != EOF)
    {
        for(j = c-1; j > 0; j--)
        {
            if(f[n][j] != 0)
            {
                break;
            }
        }

        pf("The Fibonacci number for %d is ",n);

        for( ; j >= 0; j--)
        {
            pf("%d",f[n][j]);
        }

        pf("\n");
    }
    return 0;
}
