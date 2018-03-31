#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <math.h>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>
using namespace std;

#define pf printf
#define sc scanf

vector<vector<string> >g;
string s;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

map<int,int>visit_x;
map<int,int>visit_y;

void dfs(char c,int j,int k)
{
        int x,y,i,X,Y;

        visit_x[j]=1;
        visit_y[k]=1;
        stack<pair<int,int> >st;
        pair<int,int>p;
        st.push(make_pair(j,k));
        while(!st.empty())
        {
                p=st.top();st.pop();
                x=p.first;
                y=p.second;
                visit_x[x]=1;
                visit_y[y]=1;
                for(i=0;i<4;i++)
                {
                        X=x+dx[i];
                        Y=y+dy[i];
                        char a=g[X][Y];
                        if(a==c && visit_x[X]==0 && visit_y[Y]==0)
                        {
                                st.push(make_pair(X,Y));
                        }
                }
        }
}

int main()
{
        int tst,r,c,j,i,rslt[27],k;
        char ch;
        sc("%d",&tst);
        for(i=1;i<=tst;i++)
        {
                memset(rslt,0,sizeof(rslt));
                visit_x.clear();
                visit_y.clear();
                g.clear();

                sc("%d%d",&r,&c);
                for(j=0;j<r;j++)
                {
                        cin>>s;
                        g[j].push_back(s);
                }

                for(j=0;j<r;j++)
                {
                        for(k=0;k<c;k++)
                        {
                                ch=g[j][k];
                                dfs(ch,j,k);
                                x=ch-96;
                                rslt[x]=rslt[x]+1;
                        }
                }
        }
        return 0;
}
