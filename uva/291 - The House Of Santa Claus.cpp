#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define SIZ(a) (int)a.size()

vector<int>g;
bool con[6][6];

void reset()
{
        g.clear();
        for(int i =0 ; i<6;i++)
        {
                for(int j =0 ; j <6; j++)
                {
                        con[i][j] = true;
                }
        }
    con[1][2]=con[1][3]=con[1][5]=false;
    con[2][1]=con[2][3]=con[2][5]=false;
    con[3][1]=con[3][2]=con[3][4]=con[3][5]=false;
    con[4][3]=con[4][5]=false;
    con[5][1]=con[5][2]=con[5][3]=con[5][4]=false;
}

void rec(int cur)
{
        int i;
        if(SIZ(g) == 9)
        {
                for(i = 0; i <9; i++)
                {
                        pf("%d",g[i]);
                }
                putchar('\n');
                return;
        }
        for(i = 1; i<= 5; i++)
        {
                if(!con[i][cur])
                {
                        con[i][cur] = con[cur][i] = true; g.pb(i);
                        rec(i);
                        con[i][cur] = con[cur][i] = false;g.pop_back();
                }
        }
}

int main()
{
       reset();
       g.pb(1);
       rec(1);
       return 0;
}
