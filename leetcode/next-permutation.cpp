#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(int start, int end, vector<int> &nums) {
        for (int i = start, j = end; i <= j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }

    void nextPermutation(vector<int>& nums) {
        int length = (int) nums.size();
        int index = length - 1;

        for (int i = length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == length - 1) {
            reverse(0, length - 1, nums);
            return;
        }

        int pairedIndex = index;
        for (int i = index + 1; i < length; i++) {
            if (nums[i] > nums[index]) {
                pairedIndex = i;
            }
        }

        swap(nums[index], nums[pairedIndex]);
        reverse(index + 1, length - 1, nums);
    }
};