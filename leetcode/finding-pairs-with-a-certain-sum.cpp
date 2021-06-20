#include<bits/stdc++.h>
using namespace std;

class FindSumPairs {
private:
    vector<int> first, second;
    unordered_map<int, int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        freq.clear(), first.clear(), second.clear();
        for (int val: nums1) first.push_back(val);
        for (int val: nums2) {
            second.push_back(val);
            freq[val] += 1;
        }
    }
    
    void add(int index, int val) {
        int prev = second[index];
        freq[prev]--;
        second[index] += val;
        freq[second[index]]++;
    }
    
    int count(int tot) {
        int pairs = 0;
        for (int i = 0; i < (int) first.size(); i++) {
            pairs += freq[tot - first[i]];
        }
        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */