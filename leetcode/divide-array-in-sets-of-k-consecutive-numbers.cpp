#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int length = (int) nums.size();
        map<int, int> counter;
        for (int value: nums) counter[value]++;

        for (auto p: counter) {
            int value = p.first;
            int freq = p.second;

            if (freq <= 0) continue;
            for (int i = value; i <= value + k - 1; i++) {
                if (!counter.count(i) || counter[i] < freq) return false;
                counter[i] -= freq;
            }
        }

        return true;
    }
};

int main() {
    Solution sln;
    vector<int> nums = {1,2,3,3,4,4,5,6};
    int k = 4;
    cout << sln.isPossibleDivide(nums, k) << endl;
}