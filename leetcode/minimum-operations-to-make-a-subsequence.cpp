#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int> &transformed) {
        vector<int> dp;
        for (int i = 0; i < (int) transformed.size(); i++) {
            auto iter = lower_bound(dp.begin(), dp.end(), transformed[i]);
            if (iter == dp.end()) {
                dp.push_back(transformed[i]);
            } else {
                *iter = transformed[i];
            }
        }
        return (int) dp.size();
    }

public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> index;
        for (int i = 0; i < (int) target.size(); i++) {
            index[target[i]] = i;
        }
        vector<int> transformed;
        for (int i = 0; i < (int) arr.size(); i++) {
            if (index.find(arr[i]) != index.end()) {
                transformed.push_back(index[arr[i]]);
            }
        }
        return (int) target.size() - solve(transformed);
    }
};
