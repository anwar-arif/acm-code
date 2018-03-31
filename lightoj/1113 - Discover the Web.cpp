#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int main()
{
        int tst,i;
        string cp;
        sc("%d",&tst);
        string s3="http://www.lightoj.com/";
        for(i=1;i<=tst;i++)
        {
                stack<string>backword;
                stack<string>forword;
                string s2,s;
                cp=s3;
                pf("Case %d:\n",i);
                while(cin>>s)
                {
                        if(s=="QUIT")break;
                        else if(s=="VISIT")
                        {
                                backword.push(cp);
                                cin>>s2;
                                cp=s2;
                                cout<<cp<<endl;
                                while(!forword.empty())
                                {
                                        forword.pop();
                                }

                        }
                        else if(s=="BACK")
                        {
                                if(backword.empty())
                                {
                                        cout<<"Ignored"<<endl;
                                        continue;
                                }
                                else
                                {
                                        forword.push(cp);
                                        cp=backword.top();backword.pop();
                                        cout<<cp<<endl;
                                }
                        }
                        else if(s=="FORWARD")
                        {
                                if(forword.empty())
                                {
                                        cout<<"Ignored"<<endl;
                                        continue;
                                }
                                else
                                {
                                        backword.push(cp);
                                        cp=forword.top();forword.pop();
                                        cout<<cp<<endl;
                                }
                        }
                }
        }
        return 0;
}
