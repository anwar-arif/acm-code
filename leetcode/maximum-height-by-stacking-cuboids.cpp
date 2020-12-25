/**
 * @file maximum-height-by-stacking-cuboids
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Saturday December 26 2020
 *
 * @brief 
 */
class Solution {
public:
    int inf = (int) 2e9;
    
    int canStack(vector<int> &a, vector<int> &b) {
        for (int k = 0; k < 3; k++) {
            if (a[k] < b[k]) return false;
        }
        return true;
    }
    
    int solve(int cur, vector<int> &dp, vector<vector<int>>& cuboids) {
        int n = (int) cuboids.size();
        
        int &ret = dp[cur];
        if (ret != -1) return ret;
        
        ret = 0;
        for (int i = 0; i < n; i++) {
            if (cur == i) continue;
            if (canStack(cuboids[cur], cuboids[i])) {
                ret = max(ret, solve(i, dp, cuboids));
            }
        }
        
        ret += cuboids[cur][2];
        return ret;
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        int len = (int) cuboids.size();
        
        for (int i = 0; i < len; i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        
        vector<int> dp(len + 1, -1);
        
        int answer = -inf;
        for (int i = 0; i < len; i++) {
            answer = max(answer, solve(i, dp, cuboids));
        }
        
        return answer;
    }
};