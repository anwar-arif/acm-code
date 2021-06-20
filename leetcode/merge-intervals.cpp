#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &me, vector<int> &other) {
            return (me[0] == other[0]) ? (me[1] < other[1]) : (me[0] < other[0]);
        });

        vector<vector<int>> answer;
        int left = intervals[0][0], right = intervals[0][1];
        int length = (int) intervals.size();

        for (int i = 0; i < length; i++) {
            if (intervals[i][0] >= left && intervals[i][0] <= right) {
                right = max(right, intervals[i][1]);
            } else {
                answer.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }

        answer.push_back({left, right});
        return answer;
    }
};