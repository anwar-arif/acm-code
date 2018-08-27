#include<bits/stdc++.h>
using namespace std;

int cnt;

int make(string s)
{
    int ret=0;

    for(int i=0; i<s.size(); i++)
    {
        ret=ret*10 + (s[i]-'0');
    }

    return ret;
}

string makestr(int n)
{
    string ret="";

    while(n)
    {
        ret+=(n%10)+'0';
        n/=10;
    }

    reverse(ret.begin(), ret.end());

    if(ret.size()==0) ret="0";

    return ret;
}

void fun(string s)
{
    cnt++;
    if(s=="0") return;

    int sum=0;

    for(int i=0; i<s.size(); i++) sum+=s[i]-'0';

    int now=make(s)-sum;
    string str=makestr(now);

    fun(str);
}

int main()
{
    string s;

    while(cin>>s)
    {
        cnt=0;
        fun(s);
        cout<<cnt<<endl;
    }

    return 0;
}
