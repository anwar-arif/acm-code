#include <bits/stdc++.h>
using namespace std;

int a[10] , n , taken[10];

vector<int>res;

void rec(int pos)
{
    if( SZ(res) != 0)
    {
        int len = (int)res.size();

        for(int i = 0;i < len ; i++)
        {
            cout<<res[i]<<" ";
        }

        pf("\n");

    }

    for(int i = pos ; i <= n;i++)
    {
        if(taken[i] == 0)
        {
            taken[i] = 1;

            res.pb(a[i]);

            rec(i+1);

            taken[i] = 0;

            res.pop_back();
        }
    }
}

int main()
{
      while(sc1i(n) != EOF)
      {
          mem(taken,0);

          res.clear();

          for(int i = 0 ;i <=n;i++)
          {
              a[i] = i;
          }

          rec(0);
      }
      return 0;
}
