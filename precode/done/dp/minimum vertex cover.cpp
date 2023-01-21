#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 10;
const int M = 5;

const int inf = (int) 2e9;

int dp[N][M];
int par[N];

vector<int> edges[N];

int solve(int u , int isGuard) {
	int len = (int) edges[u].size();
    if (len == 0) return 0;

	if (dp[u][isGuard] != -1) return dp[u][isGuard];

	int sum = 0;

	for (int i = 0; i < len; i++)	{
		int v = edges[u][i];
		if(v != par[u]) {
			par[v] = u;
			if (isGuard == 0) sum += solve(v, 1);
			else sum += min(solve(v, 1), solve(v, 0));
		}
	}

	return dp[u][isGuard] = sum + isGuard;
}

int main() {
    memset(dp,-1,sizeof(dp));
	int n;
	scanf("%d",&n);

	for (int i = 1; i < n; i++) {
		int u, v;

		scanf("%d %d",&u, &v);

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	int ans = 0;

	ans = min(solve(1, 1), solve(1, 0));

	printf("%d\n", ans);
	return 0;
}
