#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        int key[500],n,len,cnt,i,k;
        char a[300010];

        while(sc("%d",&n) == 1)
        {
                getchar();
                gets(a);
                len = strlen(a);
                cnt = 0;

                memset(key,0,sizeof(key));
                for(i = 0; i < len; i++)
                {
                        if( i % 2 == 0)
                        {
                                ++key[a[i] - 'a'];
                        }
                        else
                        {


                                if(key[a[i] - 'A'] == 0)
                                {
                                        ++cnt;
                                }
                                else
                                {
                                        --key[a[i] - 'A'];
                                }
                        }
                }
                pf("%d\n",cnt);
                memset(a,'0',sizeof(a));
        }
        return 0;
}
