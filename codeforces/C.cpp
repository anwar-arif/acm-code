#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e6 + 10;
const int inf = (int) 2e9;

vector <long long> primes;
vector <bool> isPrime(N, 1);

void sieve() {
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j < N; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i + 0LL);
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    sieve();
    long long n; scanf("%lld", &n);
    long long answer = n;
    for (long long p : primes) {
        if (p > (n + 1) / 2) {
            break;
        }
        if (n % p == 0) {
            answer = p;
            break;
        }
    }
    if (n > answer + answer) {
        answer = 1;
    }
    printf("%lld\n", answer);
    return 0 ;
}
