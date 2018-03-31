#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define ll long long
#define mx 1005

int n,m,conect[mx][mx],ind[mx],inp[mx];

void reset()
{
        for(int i = 1; i <= n ;i++)
        {
                ind[i] = 0;
                for(int j = 1; j <= n; j++)
                {
                        conect[i][j] = 0;

                }
        }
}

void take_input()
{
        int x,y,i,j;
        for(i = 1; i <= m; i++)
        {
                sc("%d%d",&x,&y);
                if(conect[x][y] == 0)
                {
                        ++ind[y];
                }
                conect[x][y] = 1;
        }
        for(i = 1; i <= n ;i++)
        {
                sc("%d",&inp[i]);
        }
}

bool solve()
{
        int u;
        for(int i = 1; i <= n; i++)
        {
                u = inp[i];
                if(ind[u] != 0)
                {
                        return false;
                }
                else
                {
                        for(int j = 1; j <= n; j++)
                        {
                                if(conect[u][j] == 1)
                                {
                                        --ind[j];
                                }
                        }
                }
        }
        return true;
}

int main()
{
        while(sc("%d%d",&n,&m) == 2)
        {
                reset();
                take_input();
                bool res = solve();
                if(res)
                {
                        pf("YES\n");
                }
                else
                {
                        pf("NO\n");
                }
        }
}
