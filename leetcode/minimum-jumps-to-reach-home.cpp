#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int inf = (int) 2e9;
    int limit = 0;
    int forwardJump, backwordJump;

    int solve(int pos, int backword, int target, vector<int> &forbidden, vector<vector<int>> &dp) {
        if (pos == target) return 0;
        if (pos < 0) return inf;
        if (pos >= limit) return inf;
        if (forbidden[pos]) return inf;
        

        int &ret = dp[pos][backword];
        if (ret != -1) return ret;

        ret = 1 + solve(pos + forwardJump, 0, target, forbidden, dp);
        if (!backword) ret = min(ret, 1 + solve(pos - backwordJump, 1, target, forbidden, dp));

        return ret;
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        forwardJump = a;
        backwordJump = b;

        limit = 7000;
        vector<vector<int>> dp(limit + 1, vector<int> (2, -1));

        vector<int> obstacle(max(limit + 1, 2001), 0);
        for (int val: forbidden) obstacle[val] = 1;

        int answer = solve(0, 0, x, obstacle, dp);
        return answer >= inf ? -1 : answer;
    }
};