#include <sstream>
#include<limits.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <numeric>
#include <cstring>
using namespace std;
template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}


#define    pb   push_back
#define    pp   pop_back
#define    pi   2*acos(0.0)
#define    pf   printf
#define    sf   scanf
#define    EPS  1e-10
#define    clr(a)       memset(a,0,sizeof(a))
#define    full(a)      memset(a,63,sizeof(a))
#define    max3(a,b,c)  max(a,max(b,c))
#define    min3(a,b,c)  min(a,min(b,c))
#define    sf1(a)       scanf("%d",&a)
#define    sf2(a,b)     scanf("%d%d",&a,&b)
#define    sf3(a,b,c)   scanf("%d%d%d",&a,&b,&c)
#define    sf1l(a)      scanf("%lld",&a)
#define    sf2l(a,b)    scanf("%lld%lld",&a,&b)
#define    sf3l(a,b,c)  scanf("%lld%lld%lld",&a,&b,&c)
#define    sf1d(a)      scanf("%lf",&a)
#define    sf2d(a,b)    scanf("%lf%lf",&a,&b)
#define    sf3d(a,b,c)  scanf("%lf%lf%lf",&a,&b,&c)
#define    READ(in)     freopen("in.txt","r",stdin);
#define    WRITE(out)   freopen("out.txt","w",stdout);
#define        boost    ios_base::sync_with_stdio(0)
#define    sr_pr(s1)    printf("%s",s1.c_str())
#define    fo(i,n)      for(i=0;i<n;i++)
#define    MAX
#define    MOD
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {-1,1,0,0,1-1,1,-1};

int vis[120][120],ans[120][120];
char str[120][120],str2[120][120];
int cnt=1,n,m;
int maxi=0;
int big=214748364;
void init()
{
   for(int i=0;i<=110;i++){
    for(int j=0;j<=110;j++){
        str[i][j]='.';
        ans[i][j]=big;
    }
   }

}
int check(int p,int q)
{
    int ma=big;
    for(int i=0;i<4;i++){
        int v=dx[i]+p;
        int w=dy[i]+q;
        if(v<0||v>(n+1)||w<0 || w>(m+1))continue;
        ma=min(ma,ans[v][w]);
    }
    return ma;

}
void dfs(int v,int w)
{
    vis[v][w]=1;
    ans[v][w]=0;
   // cout<<v<<" "<<w<<endl;
    for(int i=0;i<4;i++){
       int p=v+dx[i];
        int q=w+dy[i];
        if(p>=0&&p<=n+1&&q>=0&&q<=m+1&&str[p][q]=='.'&&vis[p][q]==0)dfs(p,q);
    }
}
void dfs2(int v,int w)
{
    vis[v][w]=1;
    for(int i=0;i<8;i++){
       int p=v+dx[i];
       int q=w+dy[i];
    if(p>=0&&p<=n+1&&q>=0&&q<=m+1&&str[p][q]=='T'&&vis[p][q]==0){
        if(check(p,q)<cnt){
            ans[p][q]=check(p,q)+1;
            maxi=max(maxi,ans[p][q]);
            dfs2(p,q);
        }
    }
    }


}
void fun(int d)
{
    if(d<10)printf("..");
    else if(d<100)printf("...");

}
int main()
{
    int i,j,k,l,p,q;
    while(scanf("%d%d",&n,&m)==2){
            clr(vis);
    init();
   for(i=0;i<n;i++)scanf("%s",str2[i]);
   for(p=1,i=0;p<=n;p++,i++){
    for(q=1,j=0;q<=m;q++,j++){
        str[p][q]=str2[i][j];
    }
   }
   cnt=1;
   for(j=0;j<=m+1;j++){
    if(!vis[0][j])dfs(0,j);
    if(!vis[n+1][j])dfs(n+1,j);
   }
    for(j=0;j<=n+1;j++){
    if(!vis[j][0])dfs(j,0);
    if(!vis[j][m+1])dfs(j,m+1);
   }
   maxi=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(str[i][j]=='T'&&vis[i][j]==0){
                dfs2(i,j);
                ans[i][j]=check(i,j)+1;
                maxi=max(maxi,ans[i][j]);
                cnt++;
            }
        }
    }
 for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        if(str[i][j]=='.'){
                fun(maxi);
        continue;
        }
       int c=ans[i][j];
    if(maxi>=10){
        c=ans[i][j];
        if(c>=100)printf("%d",c);
        else if(c<10)printf("..%d",c);
        else printf(".%d",c);
        continue;
    }
    printf(".%d",c);
    }
    cout<<endl;
 }
}
}
