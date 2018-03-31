#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long
#define pb push_back

int main()
{
        int g[205][205],a[205],b[205],n,i,m,k,t;
        char x[205],y[205],str[205];
        string u,v;
        while(sc("%d",&n) == 1)
        {
                map<string,int>mp;
                queue<int>q;
                for(i = 1; i <= n; i++)
                {
                        sc("%s",str);
                        u  = string(str);
                        mp[u] = i;

                }

                sc("%d",&m);

                for(i = 1; i <= m; i++)
                {
                        sc("%s %s",&x,&y);
                        u = string(x);
                        v = string(y);
                        g[mp[u]][mp[v]] = 1;
                        ++a[mp[v]];
                }

                for(i = 1; i <= n; i++)
                {
                        if(a[i] == 0)q.push(i);
                }
                k = 0;
                while(!q.empty())
                {
                        t = q.front() ; q.pop();

                        b[++k] = t;

                        for(i = 1; i <= n; i++)
                        {
                                if(g[t][i] == 1)
                                {
                                        --a[i];

                                        if(a[i] == 0)
                                        {
                                                q.push(i);
                                        }
                                }
                        }
                }

                map<string,int>::iterator it;
                for(it = mp.begin();it!=mp.end();++it)
                {
                        cout<<it->second<<endl;
                }

        }
        return 0;
}
