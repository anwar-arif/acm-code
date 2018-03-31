#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pf printf
#define ll long long
#define fill(a,x)  memset(a,x,sizeof(a))
#define pb push_back
#define SIZ(a) (int)a.size()
#define sc1i(a) scanf("%d",&a)
#define sc2i(a,b) scanf("%d%d",&a,&b)
#define sc3i(a,b,c) scnaf("%d%d%d",&a,&b,&c)

char a[500];

bool cmp(const char a,const char b)
{
    int d = tolower(a) - tolower(b);
    return d ? (d<0) : a<b;
}

int main()
{
        int n,i,l;
        sc1i(n);
        getchar();
        while(n--)
        {
               memset(a,'\0',sizeof(a));
               gets(a);
               int len=strlen(a);
               sort(a,a+len,cmp);

                do{
                cout<<a<<endl;
                }while(next_permutation(a,a+len,cmp));
        }
        return 0;
}
