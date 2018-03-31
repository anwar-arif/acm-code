#include<bits/stdc++.h>
using namespace std;
vector<int>vc[222][222];
int in[222][222],m;
bool vis[222][222];
int go[222];
set<int>st;

void dfs(int pos,int mv)
{
    if(mv==m+1)
    {
        st.insert(pos);
        return;
    }
    vis[pos][mv]=1;
    int v=go[mv];
    for(int j=0; j<vc[pos][v].size(); j++)
    {
        int p=vc[pos][v][j];
        if(!vis[p][mv+1]) dfs(p,mv+1);
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&in[i][j]);
            vc[i][in[i][j]].push_back(j);
        }
    }

    scanf("%d",&m);
    for(i=1; i<=m; i++) scanf("%d",&go[i]);
    dfs(1,1);

    set<int>::iterator it;
    printf("%d\n",st.size());
    for(it=st.begin(); it!=st.end(); it++) printf("%d ",*it);



}
