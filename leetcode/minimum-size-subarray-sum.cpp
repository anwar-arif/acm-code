#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = (int) nums.size(), answer = length + 5;
        long long sum = 0;
        for (int i = 0, hi = -1; i < length; i++) {
            while (hi + 1 < length && sum < target) {
                sum += nums[hi + 1];
                hi += 1;
            }
            if (sum >= target) {
                answer = min(answer, hi - i + 1);
            }
            sum -= nums[i];
        }

        return answer > length ? 0 : answer;
    }
};

int main() {
    Solution sln;
    vector<int> nums = {2,3,1,2,4,3};
    cout << sln. minSubArrayLen(7, nums) << endl;
}