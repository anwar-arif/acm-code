///HEADER FILES///

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdlib>
#include<complex>
#include<iomanip>
#include<utility>
#include<bitset>
#include<list>
#include<assert.h>
#include<numeric>
#include<fstream>
using namespace std;

///DEFINES///

///ALWAYS USEFUL
#define     caseprint(case)     printf("Case %d: ", case++)
#define     caseprintnl(case)   printf("Case %d:\n", case++)
#define     clr(a)              memset(a, 0, sizeof(a))
#define     mem(a, b)           memset(a, b, sizeof(a))
#define     pb                  push_back
#define     pp                  pop_back
#define     ful_vec(v)          v.begin(), v.end()
#define     sort_vec(v)         sort(fulvec(v))
#define     sf                  scanf
#define     pf                  printf
#define     NL                  pf("\n")
#define     sz(a)               (int)a.size()
#define     bitcheck(n, pos)    (n & (1<<(pos)))
#define     biton(n, pos)       (n  (1<<(pos)))
#define     bitoff(n, pos)      (n & ~(1<<(pos)))
#define     sqr(a)              ((a)*(a))

///SCAN
#define     sfs(a)              scanf("%s", &a)
#define     sfi1(a)             scanf("%d", &a)
#define     sfi2(a, b)          scanf("%d %d", &a, &b)
#define     sfi3(a, b, c)       scanf("%d %d %d", &a, &b, &c)
#define     sfi4(a, b, c, d)    scanf("%d %d %d %d", &a, &b, &c, &d)
#define     sfd1(a)             scanf("%lf", &a)
#define     sfd2(a, b)          scanf("%lf %lf", &a, &b)
#define     sfd3(a, b, c)       scanf("%lf %lf %lf", &a, &b, &c)
#define     sfd4(a, b, c, d)    scanf("%lf %lf %lf %lf", &a, &b, &c, &d)
#define     sfll1(a)            scanf("%lld", &a)
#define     sfll2(a, b)         scanf("%lld %lld", &a, &b)
#define     sfll3(a, b, c)      scanf("%lld %lld %lld", &a, &b, &c)
#define     sfll4(a, b, c, d)   scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define     sfull1(a)           scanf("%llu", &a)
#define     sfull2(a, b)        scanf("%llu %llu", &a, &b)
#define     sfull3(a, b, c)     scanf("%llu %llu %llu", &a, &b, &c)
#define     sfull4(a, b, c, d)  scanf("%llu %llu %llu %llu", &a, &b, &c, &d)

///GEOMETRY
#define     ang(a, b, c)            acos((sqr(b)+sqr(c)-sqr(a))/(2.0*b*c))
#define     dist(x1, y1, x2, y2)    sqrt(sqr(x1-x2)+sqr(y1-y2))

///TYPES///
typedef     long long           ll;
typedef     unsigned long long  ull;
typedef     pair<int, int>      pii;

///TEMPLATES///
template<class T1>void deb(T1 e)
{
    cout <<"-->"<< e << endl;
}
template<class T1, class T2> void deb(T1 e1, T2 e2)
{
    cout <<"-->"<< e1 << " " << e2 << endl;
}
template<class T1, class T2, class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << endl;
}
template<class T1, class T2, class T3, class T4> void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template<class T1, class T2, class T3, class T4, class T5> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template<class T1, class T2, class T3, class T4, class T5, class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6 << endl;
}

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//int x[] = {0,0,-1,1};//4-ways
//int y[] = {1,-1,0,0};//4-ways
//int x[] = {-1,-1,-1,0,0,1,1,1};//8-ways
//int y[] = {-1,0,1,-1,1,-1,0,1};//8-ways
//int x[] = {-2,-2,2,2,1,1,-1,-1};//knight moves
//int y[] = {1,-1,1,-1,2,-2,2,-2};//knight moves

///CONSTANTS
#define     pi                  acos(-1.0)
#define     ex                  exp(1)
#define     oo                  (1<<30)

///OTHERS
#define     READ                freopen("/home/mridul/Desktop/input.txt","r",stdin);
#define     WRITE               freopen("out.txt","w",stdout);
#define     accelerate          ios::sync_with_stdio(false)
#define     debug               printf("Ok\n")
#define     MOD                 1000000007
#define     M                   500000

vector<int>graph[M], SCC[M];
stack<int>S;
int cnt, disc, in_stack[M], DT[M], low_DT[M];


void Tarjan(int u)
{
    ///param - "int root" //for Articulation Point
    DT[u]=low_DT[u]=++disc;
    in_stack[u]=1;
    S.push(u);

    ///int child=0; //for Articulation Point

    for(int i=0; i<sz(graph[u]); i++)
    {
        int v=graph[u][i];

        if(DT[v]==-1)
        {
            ///parent[v]=u; //for Articulation Point & Bridge

            Tarjan(v);
            low_DT[u]=min(low_DT[v], low_DT[u]);

            ///if(DT[u]<low_DT[v]) Bridge.pb(make_pair(min(u, v), max(u, v))); //for Bridge
            ///if(DT[u]<=low_DT[v] && u!=root) AP.insert(u); //for Articulation Point
            ///child++; //for Articulation Point
        }

        else if(in_stack[v] == 1)
        {
            ///if(parent[u]!=v) //for Articulation Point & Bridge

            low_DT[u]=min(low_DT[u], DT[v]);
        }

        ///if(u==root && child>1) AP.insert(u);
    }

    if(DT[u]==low_DT[u])
    {
        cnt++;
        //deb(u);
        //SCC[cnt].pb(u);
        while(!S.empty() && DT[u]<=low_DT[S.top()])
        {
            SCC[cnt].pb(S.top());
            in_stack[S.top()]=0;
            S.pop();
        }
    }
}

int main()
{

    int n , e , u , v ;
    cin >> n >> e ;
    for( int i = 0 ; i < e; i++ ) {
        cin >>u >> v ;
        --u , --v ;
        graph[u].push_back(v) ;
    }
    disc=0;
    cnt=0;
    mem(DT, -1);
    for(int i=0; i<n; i++) if(DT[i]==-1) Tarjan(i);

    deb(cnt);

    for(int i=1; i<=cnt; i++)
    {
        for(int j=0; j<sz(SCC[i]); j++) pf("%d ", SCC[i][j]);
        NL;
    }

    return 0;
}
