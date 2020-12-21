
class Solution {
public:
    const int inf = (int) 2e9;

    int maxResult(vector<int>& nums, int k) {
        int len = (int) nums.size();
        vector<int> dp(len + 1, 0);
        deque<int> deq;

        for (int i = 0; i < len; i++) {
            while (!deq.empty() && deq.front() + k < i) deq.pop_front();
            dp[i] = nums[i] + dp[deq.empty() ? 0 : deq.front()];
            
            while (!deq.empty() && dp[i] >= dp[deq.back()]) deq.pop_back();
            deq.push_back(i);
        }

        return dp[len - 1];
    }
};
