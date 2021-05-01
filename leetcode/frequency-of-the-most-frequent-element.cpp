#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, vector<int>& nums, vector<long long>& sum, int k) {
        if (index == 0) return 1;

        int length = (int) nums.size();
        int required = nums[index];
        int answer = 0;

        int lo = 0, hi = index - 1, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            long long csum = sum[index - 1] - (mid - 1 >= 0 ? sum[mid - 1] : 0);
            long long total = ((long long) (index - mid) * (long long) required) - csum;

            if (total <= k) {
                hi = mid - 1;
                answer = (index - mid + 1);
            } else {
                lo = mid + 1;
            }
        }

        return answer;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int length = (int) nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> sum(length, 0);
        for (int i = 0; i < length; i++) {
            sum[i] = nums[i];
            if (i) sum[i] += sum[i - 1];
        }

        int answer = 0;
        for (int i = 0; i < length; i++) {
            answer = max(answer, solve(i, nums, sum, k));
        }

        return answer;
    }
};