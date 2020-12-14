class Solution {
public:
    int solve(int left, int right, vector<int> &arr, vector<vector<int>> &dp) {
        if (left + 1 == right) return 0;
        
        int &ret = dp[left][right];
        if (ret != -1) return ret;
        
        ret = 0;
        for (int i = left + 1; i < right; i++) {
            ret = max(ret, arr[left] * arr[i] * arr[right] + 
                      solve(left, i, arr, dp) + 
                      solve(i, right, arr, dp));
        }
        
        return ret;
    }
    
    int maxCoins(vector<int>& nums) {
        int len = (int) nums.size();
        vector<vector<int>> dp(len + 2, vector<int> (len + 2, -1));
        vector<int> arr(len + 2);
        
        for (int i = 0; i < len + 2; i++) {
            if (i == 0 || i == len + 1) arr[i] = 1;
            else arr[i] = nums[i - 1];
        }
        
        int answer = solve(0, len + 1, arr, dp);
        return answer;
    }
};
