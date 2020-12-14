class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int) nums.size();
        int one = 0;
        for (int i = 0; i < n; i++) if (nums[i] == 1) {
            one += 1;
            break;
        }
        if (one == 0) return 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]);
            if (index == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[index] = -abs(nums[index]);
            }
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }
        if (nums[0] > 0) return n;
        return n + 1;
    }
};
