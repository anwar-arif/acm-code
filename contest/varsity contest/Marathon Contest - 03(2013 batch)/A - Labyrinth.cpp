#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long
#define pb push_back
#define mx 40

int dx[] = {1 , 0 , -1 , 0};
int dy[] = {0 ,1 , 0 , -1};
int cnt , n;
bool visit[mx][mx];
char s[150][150];

int i,X,Y,j;

void init()
{
        for(i = 0 ; i<= n ;i++)
        {
                for(j = 0 ; j <= n ; j++)
                {
                        visit[i][j] = false;
                }
        }
}


void cal(int r,int c)
{
        if(s[r][c] == '#'){++cnt; return;}

        else if(s[r][c] == '.')
        {
                if(visit[r][c] == false)
                {
                        visit[r][c] = true;

                        for(int i = 0 ; i< 4 ;i++)
                        {
                                int X  = r + dx[i];
                                int Y = c + dy[i];

                                if(X < 1 || Y < 1 || X > n || Y > n){++cnt;}
                                if(X <=n && Y <= n && X >=1 && Y >= 1){cal(X,Y);}
                        }
                }

                else if(visit[r][c] == true)return;
        }
}

int main()
{

        while(sc("%d",&n) == 1)
        {
                getchar();
                for(i = 1; i <= n ; i++)
                {
                        for(j = 1; j <= n; j++)
                        {
                                sc("%c",&s[i][j]);
                        }
                        getchar();
                }
                init();
                cnt = 0;
                cal(1,1);
                if(visit[n][n] == false)
                {
                        cal(n,n);
                }
                pf("%d\n",(cnt-4)*9);

        }
        return 0;
}
