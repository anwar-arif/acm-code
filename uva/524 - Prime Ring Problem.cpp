#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long
#define pb push_back
#define SIZ(a) (int)a.size()

vector<int>v;
int taken[17],n;

bool isprime(int num)
{
        for(int i = 2; i*i <= num ;i++)
        {
                if(num % i == 0)return false;
        }
        return true;
}

bool valid()
{
        if( isprime( ( v[0] + v[SIZ(v)-1] ) ) )
        {
                for(int i = SIZ(v) - 1; i>=1; i--)
                {
                        if(! isprime(v[i] + v[i-1]) )return false;
                }
                return true;
        }
        return false;
}


void reset()
{
        v.clear();
        memset(taken,0,sizeof(taken));
}

void rec()
{
        if(SIZ(v) == n)
        {
                if(valid()){
                    pf("%d",v[0]);
                   for(int i = 1 ; i<n; i++){pf(" %d",v[i]);}
                pf("\n");}
                return;
        }
        for(int i = 2; i <= n ;i++)
        {
                if(taken[i] == 0 && ( isprime(v[SIZ(v)-1]+i) ) )
                {
                        taken[i] = 1; v.pb(i);
                        rec();
                        taken[i] = 0; v.pop_back();
                }
        }
}

int main()
{
        int cas = 0;
        while(sc("%d",&n) == 1)
        {
                reset();
                v.pb(1);
                if(cas){pf("\n");}
                pf("Case %d:\n",++cas);
                rec();
        }
        return 0;
}
