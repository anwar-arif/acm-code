#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back
#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)
#define sc1ll(a) sc("%I64d",&a)
#define sc2ll(a,b) sc("%I64d%I64d",&a,&b)
#define sc3ll(a,b,c) sc("%I64d%I64d%I64d",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define pi acos(-1)

int cnt,n,k,taken[27];
char a[27];
vector<char>v;

void rec()
{
        if((int)v.size() == n){
                if(cnt >=k)return;
                for(int i = 0 ; i<n;i++){
                        pf("%c",v[i]);
                }
                pf("\n");
                ++cnt;
                return;
        }
        else{
                for(int i = 0;i<n;i++){
                        if(cnt >= k)break;
                        if(taken[i] == 0){
                                taken[i] = 1;
                                v.push_back(a[i]);
                                rec();
                                taken[i] = 0;
                                v.pop_back();
                        }
                }
        }
}

int main()
{
        int tst,i,cas;
        sc1i(tst);
        for(i = 0 ; i < 26;i++){
                a[i] = 'A'+i;
        }
        for(cas = 1; cas<= tst;cas++){
                sc2i(n,k);
                memset(taken,0,sizeof(taken));
                v.clear();
                cnt = 0;
                pf("Case %d:\n",cas);
                rec();
        }
        return 0;
}
