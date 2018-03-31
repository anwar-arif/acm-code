#include <bits/stdc++.h>
using namespace std;


string cal(string a,int n)
{
    reverse(a.begin(),a.end());

    int len = (int)a.size();

    int carry = 0;

    string b;

    int x;

    for(int i = 0 ;i < len;i++)
    {
        x = (a[i] - '0')*n + carry;

        b += (x%10) + '0';

        carry = x / 10;
    }

    while(carry > 0)
    {
        b += (carry % 10) + '0';

        carry /= 10;
    }

    reverse(b.begin(),b.end());

    return b;
}

int main()
{
    int n,i;

    string s[SIZ+5];

    s[0] = "1";
    s[1] = "1";

    for(i = 2; i<= SIZ;i++)
    {
        s[i] = cal(s[i-1],i);
    }

    while(sc1i(n) != EOF)
    {
        pf("%d!\n",n);

        cout<<s[n]<<endl;
    }

    return 0;
}
