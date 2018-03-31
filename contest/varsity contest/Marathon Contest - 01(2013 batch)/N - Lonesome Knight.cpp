#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

int main()
{
        int n,x,i,y,X,Y,cnt,j;
        char ch;
        sc("%d",&n);
        for(i=1;i<=n;i++)
        {
                getchar();
                sc("%c%d",&ch,&y);
                x = ch - 96;
                cnt = 0;

                for(j=0;j<8;j++)
                {
                        X = x + dx[j];
                        Y = y + dy[j];
                        if(X>=1 && X<=8 && Y>=1 && Y<=8){++cnt;}
                }
                pf("%d\n",cnt);
        }
        return 0;
}
