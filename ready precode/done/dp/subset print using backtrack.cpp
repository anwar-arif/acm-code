#include <bits/stdc++.h>
using namespace std;

const int N = (int) 10;

int a[N], n, taken[N];

vector<int> res;

void rec(int pos) {
    int len = (int) res.size();
    if (len != 0) {
        for (int i = 0; i < len; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }

    for (int i = pos; i <= n; i++) {
        if(taken[i] == 0) {
            taken[i] = 1;

            res.push_back(a[i]);

            rec(i + 1);

            taken[i] = 0;

            res.pop_back();
        }
    }
}

int main() {
      while(scanf("%d", &n) != EOF) {
          memset(taken, 0, sizeof(taken));

          res.clear();

          for (int i = 0; i <= n; i++) {
              a[i] = i;
          }

          rec(0);
      }
      return 0;
}
