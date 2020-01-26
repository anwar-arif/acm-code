#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxProfit = 0, i = 0;
		int peak = prices[0], valley = peak;
		while (i < prices.size() - 1) {
			while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;
			valley = prices[i];

			while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;
			peak = prices[i];
			
			maxProfit += peak - valley;	
		}
		return maxProfit;
    }
};

int main() {
	// Solution sln = new Solution();
	vector <int> prices{7,1,5,3,6,4};
	printf("%d\n", Solution().maxProfit(prices));
    return 0 ;
}
