#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define ll long long

map<int,int>par;
int n;

void reset()
{
        for(int i = 1; i <= n ;i++)
        {
                par[i] = i;
        }
}

int findpar(int r)
{
        return (par[r] == r)? r : findpar(par[r]);
}

int main()
{
        int wrong,right,u,v,tst;
        char ch;
        bool t = false;
        sc("%d",&tst);
        while(tst--)
        {

        if(t){pf("\n");}
        t = true;

        sc("%d",&n);
        getchar();

        reset();

        right = 0;
        wrong = 0;

        while(sc("%c %d %d",&ch,&u,&v) != EOF)
        {
                getchar();
                if(ch == 'c')
                {
                        par[v] = u;
                }
                if(ch == 'q')
                {
                        u = findpar(u);
                        v = findpar(v);
                        if(u == v)++right;
                        else ++wrong;
                }
        }
        pf("%d,%d\n",right,wrong);

        }
        return 0;
}
