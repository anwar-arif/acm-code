class Solution {
public:
    const int inf = (int) 2e9;
    
    int solve(int d, int indx, int days, int len, vector<int> &jobs,
             vector<vector<int>> &dp) {
        if (d == days) {
            if (indx >= len) return 0;
            return inf;
        }
        if (indx >= len) return inf;
        
        int &ret = dp[d][indx];
        if (ret != -1) return ret;
        
        ret = inf;
        int mx = 0;
        for (int i = indx; i < len; i++) {
            mx = max(mx, jobs[i]);
            ret = min(ret, mx + solve(d + 1, i + 1, days, len, jobs, dp));
        }
        
        return ret;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = (int) jobDifficulty.size();
        vector<vector<int>> dp(d + 2, vector<int>(len + 2, -1));
        
        int answer = solve(0, 0, d, len, jobDifficulty, dp);
        if (answer == inf) answer = -1;
        
        return answer;
    }
};
