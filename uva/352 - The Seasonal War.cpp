#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
#define pf printf
#define sc scanf

string g[26];
int n;
int visit[26][26];

int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};

void dfs(int i,int j)
{
        int x,y,X,Y,k;
        stack<pair<int,int> >st;
        pair<int,int>p;
        st.push(make_pair(i,j));
        while(!st.empty())
        {
                p=st.top();st.pop();
                x=p.first;
                y=p.second;
                visit[x][y]=1;
                for(k=0;k<8;k++)
                {
                        X=x+dx[k];
                        Y=y+dy[k];
                        if(X>=0 && X<n && Y>=0 && Y<n && g[X][Y]=='1' && visit[X][Y]==0)
                        {
                                st.push(make_pair(X,Y));
                        }
                }
        }
}

int main()
{
        int i,j,cas=0,count;
        char ch;
        while(sc("%d",&n)==1)
        {
                getchar();

                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                visit[i][j]=0;
                        }
                }

                for(i=0;i<n;i++)
                {
                        cin>>g[i];
                }
                getchar();
                count=0;
                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                if(g[i][j]=='1' && visit[i][j]==0)
                                {
                                        ++count;
                                        dfs(i,j);
                                }
                        }
                }
                pf("Image number %d contains %d war eagles.\n",++cas,count);
        }
        return 0;
}
