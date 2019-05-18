#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 10;
const int inf = (int) 2e9;

int typ[N], height[N], n, pre[N];
long long dp[N];

int main() {
//    freopen("in.txt", "r", stdin);
    int T, cas = 0; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &typ[i], &height[i]);
        }
        map <int, int> last;
        for (int i = 1; i <= n; i++) {
            pre[i] = max(pre[i - 1], last[typ[i]] + 1);
            last[typ[i]] = i;
        }
        deque <int> que;
        dp[1] = height[1];
        que.push_front(1);
        for (int i = 2; i <= n; i++) {
            while (!que.empty() && que.front() < pre[i]) que.pop_front();
            while (!que.empty() && height[que.back()] <= height[i]) que.pop_back();
            que.push_back(i);
            dp[i] = dp[pre[i] - 1] + height[que[0]];
            for (int j = 1; j < que.size(); j++) {
                dp[i] = min(dp[i], dp[que[j - 1]] + height[que[j]]);
            }
        }
        printf("Case %d: %lld\n", ++cas, dp[n]);
    }
    return 0 ;
}
