#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int length = (int) nums.size();
        int lo = 0, hi = nums[length - 1] - nums[0], mid, answer;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            int count = 0;
            for (int i = 0, hi = -1; i < length; i++) {
                while (hi + 1 < length && (nums[hi + 1] - nums[i] <= mid)) hi += 1;
                count += hi - i;
            }

            if (count >= k) {
                answer = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return answer;
    }
};