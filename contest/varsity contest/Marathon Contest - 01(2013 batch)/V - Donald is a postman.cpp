#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

map<string , int>m;

void cal()
{

        m["Alice"]  = 1;     m["Bambi"]  = 2;   m["Dumbo"]  = 3;
        m["Ariel"]  = 1;     m["Belle"]  = 2;   m["Genie"]  = 3;
        m["Aurora"] = 1;     m["Bolt"]   = 2;   m["Jiminy"] = 3;
        m["Phil"]   = 1;     m["Mulan"]  = 2;   m["Kuzko"]  = 3;
        m["Peter"]  = 1;     m["Mowgli"] = 2;   m["Kida"]   = 3;
        m["Olaf"]   = 1;     m["Mickey"] = 2;   m["Kenai"]  = 3;
        m["Phoebus"]= 1;     m["Silver"] = 2;   m["Tarzan"] = 3;
        m["Ralph"]  = 1;     m["Simba"]  = 2;   m["Tiana"]  = 3;
        m["Robin"]  = 1;     m["Stitch"] = 2;   m["Winnie"] = 3;

}

int main()
{
        int n,i,cur,sum,x;
        string s;
        cal();
        while(sc("%d",&n) == 1)
        {
                cur = 1;sum = 0;
                for(i = 1; i<= n;i++)
                {
                        cin>>s;
                        x = cur - m[s];
                        if(x<0)x = x * (-1);
                        sum += x;
                        cur = m[s];
                }
                pf("%d\n",sum);
        }
        return 0;

}
