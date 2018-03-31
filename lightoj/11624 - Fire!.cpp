#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

string g[1005];

queue<pair<int,int> >q;

void init()
{
        int i,j;
        for(i=0;i<=r;i++)
        {
                for(j=0;j<=c;j++)
                {
                        fvisit[i][j]=5000;
                        jvisit[I][J]=0;
                }
        }

}

void work()
{
        while(!q.empty())
        {
                p=q.front();q.pop();
                a=p.first;
                b=p.second;
                for(i=0;i<4;i++)
                {
                        A=a+dx[i];
                        B=b+dy[i];
                        if(g[A][B]!='#' && )
                }
        }
}

int main()
{
        int tst,r,c,i;
        sc("%d",&tst);
        while(tst--)
        {
                sc("%d%d",&r,&c);
                getchar();

                init();

                for(i=0;i<r;i++)
                {
                       for(j=0;j<c;j++)
                       {
                               sc("%c",&g[i][j]);
                               if(g[i][j]=='F')
                               {
                                       q.push(make_pair(i,j));
                               }
                               if(g[i][j]=='J')
                               {
                                       x=i;
                                       y=j;
                               }
                       }
                       getchar();
                }

                work();

        }
        return 0;
}
