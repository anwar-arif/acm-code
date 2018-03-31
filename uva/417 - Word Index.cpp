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

int main()
{
        int i,n,x,r;
        char a[29];
        string ar[99999];
        map<string,int>msi;
        map<int,string>mis;
        string s,s1,s2;
        for(i = 1;i<=26;i++){
                a[i] = 'a'+(i-1);
                s = a[i];
                ar[i] = s;
                msi[s] = i;
                mis[i] = s;//cout<<s<<endl;
        }
        int cnt = 26;
        for(i = 27;i<= 123456;i++){
                x = i/26;r=i%26;
                if(r+1 > x){
                        s1 = mis[x];s2=mis[1+r];
                        s=s1+s2;
                        msi[s] = ++cnt;
                        mis[cnt] = s;
                        //if(cnt == 83681)break;
                }
        }
        while((cin>>s1)){
                cout<<msi[s1]<<endl;
        }
        return 0;
}
