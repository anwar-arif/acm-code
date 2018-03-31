#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long
#define pb push_back
#define SIZ(a) (int)a.size()
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc scanf

vector<char>res;
char a[31];
int taken[31];
int n;

void rec(int len)
{
        if( (SIZ(res) == n) )
        {
                for(int i = 0  ; i< n ;i++)
                {
                        pf("%c",res[i]);
                }
                pf("\n");
                return;
        }
        for(int i = 0 ;i < len; i++)
        {
                int siz = res.size();

                if(taken[i] == 0)
                {
                        if(siz> 0 && res[siz-1] > a[i])continue;

                        taken[i] = 1; res.pb(a[i]);
                        rec(len);
                        taken[i] = 0; res.pop_back();
                        while(a[i] == a[i+1])i++;
                }
        }
}

void reset()
{
        res.clear();
        memset(a,'\0',sizeof(a));
        memset(taken,0,sizeof(taken));
}

int main()
{
        while(sc("%s %d",a,&n) == 2)
        {
                int l = strlen(a);
                sort(a,a+l);
                rec(l);
                reset();
        }
        return 0;
}
