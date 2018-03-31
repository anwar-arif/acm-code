#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define ll long long
#define siz 120

set < int  > st;
int edge[siz][siz];
int s[siz];

void reset()
{
        for(int i = 0 ; i <= 110; i ++)
        {
                for(int j  =0  ; j <= 110 ; j++)
                {
                        edge[i][j] = -1;
                }
        }
}


int main()
{
        int u,v,i,j,k,mx,cost;
        double ans;
        int cas = 0;

        while(sc("%d%d",&u,&v) == 2)
        {
                if(u == 0 && v == 0)break;
                mx = -1;

                reset();

                st.clear();
                st.insert(u);
                st.insert(v);

                edge[u][v] = 1;

                while(sc("%d%d",&u,&v) == 2)
                {
                        if(u == 0 && v == 0)break;
                        st.insert(u);
                        st.insert(v);

                        edge[u][v] = 1;
                }

                mx = st.size();
                int k = 0;

                for(set<int>::iterator it = st.begin(); it != st.end();++it)
                {
                        s[++k] = *it;
                }

                for(k = 1; k <= mx; k++)
                {
                        for(i = 1 ; i <= mx; i++)
                        {
                                for(j = 1 ; j <= mx ;j++)
                                {
                                        if(i == j){edge[s[i]][s[j]] = 0;}
                                        else edge[s[i]][s[j]] = min( edge[s[i]][s[j]], ( edge[s[i]] [s[k]] + edge[s[k]] [s[j]] ) );
                                }
                        }
                }

                cost = 0 ;

                for(i = 1 ; i <= mx; i++)
                {
                        for(j = 1 ; j <= mx; j++)
                        {
                                cost += edge[s[i]][s[j]];//pf("%d\n",edge[s[i]][s[j]]);
                        }
                }


                ans = (double)cost /(double) (mx * (mx-1));

                pf("Case %d: average length between pages = %0.3lf clicks\n",++cas,ans);
        }
        return 0;
}
