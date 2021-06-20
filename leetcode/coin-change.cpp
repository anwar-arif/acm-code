#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	const int inf = (int) 1e9;

	int coinChange(vector<int>& coins, int amount) {
		int length = (int) coins.size();
		vector<vector<int>> dp(length + 1, vector<int>(amount + 1, inf));
		for (int i = 0; i < length; i++) {
			for (int j = 0; j <= amount; j++) {
				if (i == 0 && j == 0) dp[i][j] = 0;
				else if (j == 0) dp[i][j] = 0;
				else {
					dp[i][j] = dp[i - 1][j];
					if (j - coins[i] >= 0) {
						dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i]]);
						if (i > 0) {
							dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
						}
					}
				}
			}
		}
		return dp[length - 1][amount];
	}
};

int main() {
	Solution sln;
	int amount = 11;
	vector<int> coins = {1, 2, 5};
	cout << sln.coinChange(coins, amount) << endl;
}
