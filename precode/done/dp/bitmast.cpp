#include<bits/stdc++.h>
using namespace std;

const int inf = (int) 2e9;

int on(int n, int pos) {return n=n|(1<<pos);}

void off(int &n, int pos) { n = n & ~(1<<pos);}

bool check(int n, int pos) {return (bool)(n&(1<<pos));}

int n,dp[(1<<15)+2], w[20][20];

int rec(int mask) {
    if (mask == (1 << n) - 1) return 0;
    if (dp[mask] != -1) return dp[mask];

    int mn = inf;

    for (int i = 0; i < n; i++) {
        if (check(mask, i) == 0) {
            int p = w[i][i];

            for (int j = 0; j < n; j++) {
               if (i != j && check(mask, j) == 1) {
                    p += w[i][j];
               }
            }

            int ret = p + rec(on(mask, i));

            mn = min(mn, ret);
        }
    }
    return dp[mask] = mn;
}

int main() {
      while (scanf("%d", &n) != EOF) {
          memset(dp, -1, sizeof(dp));
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < n; j++) {
                  scanf("%d", &w[i][j]);
              }
          }

          int res = rec(0);
          printf("ans %d\n", res);
      }
      return 0;
}
/*
complexity :  (2^n)*(n^2);
*/
