#include <bits/stdc++.h>
using namespace std;

const int N = 1000+5;
const int M = 1000000+7;

int on(int n,int pos){return n |= (1 << pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}

int primes[80000] , status[(M/32)+5] , k;

void sieve(){
    for(int i = 3; i*i <= M ; i+= 2){
        if(check(status[i >> 5] , i&31) == 0){
            for(int j = i*i ; j <= M; j += (i << 1)){
                status[j >> 5] = on(status[j>>5] , j&31);
            }
        }
    }
    primes[++k] = 2;
    for(int i = 3; i<= M; i+= 2){
        if(check(status[i >> 5] , i&31) == 0){
            primes[++k] = i;
        }
    }
}

int main(){
    sieve();
    int n;
    while(scanf("%d",&n) == 1){
        if(n == 0)break;
        int m = n;
        int cnt = 0;
        for(int i = 1; primes[i]*primes[i] <= n;i++){
            if(n % primes[i] == 0){
                while(n % primes[i] == 0){
                    n /= primes[i];
                }
                ++cnt;
            }
        }
        if(n > 1)++cnt;
        printf("%d : %d\n",m,cnt);
    }
    return 0;
}

