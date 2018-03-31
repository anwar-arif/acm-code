#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back

vector<int>v;
int main()
{
        int n,i,x;
        while(sc("%d",&n)==1)
        {
                if(n==0)break;
                v.clear();
                for(i=0;i<n;i++)
                {
                        sc("%d",&x);
                        v.pb(x);
                }
                i=0;
                sort(v.begin(),v.end());
                for(vector<int>::iterator it=v.begin();it!=v.end();++it)
                {
                        if(i!=0){pf(" ");}
                        cout<<*it;
                        ++i;
                }
                pf("\n");
        }
        return 0;
}
