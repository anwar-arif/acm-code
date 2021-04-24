#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> found(k, false);
        int modulus = 0;
        for (auto value: nums) {
            modulus += value;
            modulus %= k;
            if (found[modulus]) return true;
            found[modulus] = true;
        }
        return false;
    }
};