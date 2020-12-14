class Solution {
public:
    
    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        int lens = (int) s.size();
        int lenp = (int) p.size();
        
        if (i == lens && j == lenp) return 1;
        int &ret = dp[i][j];
        if (ret != -1) return ret;
        
        ret = 0;
        if (p[j] == '*') {
            return ret = solve(i, j + 1, s, p, dp);
        }
        if (i < lens && j < lenp && (s[i] == p[j] || p[j] == '.')) {
            ret |= solve(i + 1, j + 1, s, p, dp);
        }
        if (j + 1 < lenp && p[j + 1] == '*') {
            ret |= solve(i, j + 1, s, p, dp);
            if (i < lens && (s[i] == p[j] || p[j] == '.')) ret |= solve(i + 1, j, s, p, dp);
        }
        return ret;
    }
    
    bool isMatch(string s, string p) {
        int lens = (int) s.size();
        int lenp = (int) p.size();
        
        vector<vector<int>> dp(lens + 2, vector<int>(lenp + 2, -1));
        return solve(0, 0, s, p, dp);
    }
};
