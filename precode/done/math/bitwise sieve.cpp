#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf

int on(int n,int pos){ n=n|(1<<pos);}
void off(int &n,int pos){ n = n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}

#define MX 100

int status[(MX/32)+2];

void sieve()
{
    for(int i = 3;i*i <= MX;i += 2)
    {
        //if bit is 0 then it is prime

        if(check(status[i/32],i%32) == false)
        {
            for(int j = i*i ; j <=MX; j+= 2*i)
            {
                status[j/32] = on(status[j/32],j%32);
            }
        }
    }

    pf("2");

    for(int i = 3 ; i <= MX ; i += 2)
    {
        if(check(status[i/32] , i%32 ) == false) pf(" %d",i);
    }
    pf("\n");
}

int main()
{
      sieve();
      return 0;
}
