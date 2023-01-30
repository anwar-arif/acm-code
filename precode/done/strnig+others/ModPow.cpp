#include<bits/stdc++.h>
using namespace std ;

const long long mod = 998244353;

inline void add(long long &a, long long b) {
  a += b ;
  if(a >= mod) a -= mod ;
}

inline void sub(long long &a, long long b) {
  a -= b ;
  if(a < 0) a += mod ;
}

inline long long mul(long long a, long long b) {
  return ((long long) a * b % mod) ;
}

inline long long modpow(long long b, long long p) {
  long long res = 1 ;
  while(p > 0) {
    if((p & 1LL)) {
      res = mul(res, b) ;
    }
    b = mul(b, b) ;
    p >>= 1LL ;
  }
  return res ;
}
/*(x)^(-1)*/
inline long long modinv(long long b) {
    return modpow(b, mod - 2) ;
}

int main() {
    cout << modpow(2, 35) << endl ;
    return 0 ;
}
