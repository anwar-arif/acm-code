#include<bits/stdc++.h>
using namespace std;
int dx[]= {0,0,1,-1};//4 side move
int dy[]= {-1,1,0,0};//4 side move
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,i,j,k;
    string in[111];
    cin >> n>>m;
    for(i=0; i<n; i++)
    {
        cin >> in[i];
    }
    int cnt=0;
    for(i=0; i<n; i++)
    {

        for(j=0; j<m; j++)
        {
            cnt+=(6*(in[i][j]-48));
            for(k=0; k<4; k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=n || y>=m || x<0 || y<0) continue;
                int mn=min(in[i][j]-48,in[x][y]-48);
                cnt-=mn;
            }
            cnt-=max(0,2*(in[i][j]-49));
        }
    }
    cout <<cnt<<endl;
    return 0;
}
