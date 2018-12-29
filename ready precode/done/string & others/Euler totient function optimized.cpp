
#include <bits/stdc++.h>
using namespace std;

#define SIZ 10000+5

int phi[SIZ];

void cal_phi()
{
    for(int i = 1; i < SIZ ; i++)
    {
        phi[i] = i;
    }
    for(int p = 2; p < SIZ ; p++)
    {
        if(phi[p] == p)//p is prime
        {
            for(int k = p ; k < SIZ ; k += p)
            {
                phi[k] -= phi[k]/p;
            }
        }
    }
}

int main()
{
      cal_phi();
      int n;
      while(scanf("%d" , &n) == 1)
      {
          printf("%d\n",phi[n]);
      }
      return 0;
}
