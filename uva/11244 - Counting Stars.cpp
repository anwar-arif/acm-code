#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define mx 105
//8 side move
int dx[] = {1, 1, 1, 0, -1, -1,-1, 0};
int dy[] ={-1, 0, 1, 1, 1, 0, -1, -1};

int r,c,visit[mx][mx];
char a[mx][mx];


int main()
{
        int r,c,i,j,cnt,t,k,X,Y;

        while(sc("%d%d",&r,&c) == 2)
        {
                if(r == 0 && c == 0)break;
                getchar();

                for(i = 0 ; i < mx; i++)
                {
                        for(j = 0 ; j < mx; j++)
                        {
                                visit[i][j] = 0;
                        }
                }

                for(i = 1; i <= r; i++)
                {
                        for(j = 1 ; j <= c; j++)
                        {
                                sc("%c",&a[i][j]);

                        }
                        getchar();
                }

                 cnt = 0;

                for(i = 1 ;i <= r; i++)
                {
                        for(j = 1 ; j <= c; j++)
                        {
                                if(a[i][j] == '*' && visit[i][j] == 0)
                                {
                                        t = 0;
                                        for(k = 0 ; k <8 ; k++)
                                        {
                                                X = i + dx[k];
                                                Y = j + dy[k];
                                                if(X>0 && X <= r && Y >0 && Y <= c && a[X][Y] == '*')
                                                {
                                                        visit[X][Y] = 1;t = 1;
                                                }
                                        }
                                        if(t == 0)++cnt;
                                }
                        }
                }

                pf("%d\n",cnt);
        }
        return 0;
}
