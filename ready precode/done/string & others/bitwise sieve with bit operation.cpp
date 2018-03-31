#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int on(int n,int pos){return n=n|(1<<pos);}
void off(int &n,int pos){ n = n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}

#define MX 100

int status[(MX/32)+2];

void sieve()
{
    for(int i = 3;i*i <= MX;i += 2)
    {
        //if bit is 0 then it is prime

        //2^5 = 31 i/32 = i >> 5

        // i % 32 = i & 31
        if(check(status[i >> 5] , i & 31) == false)
        {
            for(int j = i*i ; j <=MX; j+= (i << 1 ) )
            {
                status[j >> 5] = on(status[j >> 5] , j & 31);
            }
        }
    }

    pf("2");

    for(int i = 3 ; i <= MX ; i += 2)
    {
        if(check(status[i >> 5] , i & 31 ) == false) pf(" %d",i);
    }
    pf("\n");
}

int main()
{
      sieve();
      return 0;
}

