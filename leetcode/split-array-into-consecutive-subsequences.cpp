class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int length = (int) nums.size();
        unordered_map<int, int> counter, tails;
        for (int value: nums) counter[value] += 1;

        for (int value: nums) {
            if (counter[value] == 0) {
                continue;
            } else if (tails[value]) {
                tails[value]--;
                tails[value + 1]++;
            } else if (counter[value + 1] && counter[value  + 2]) {
                counter[value + 1]--;
                counter[value + 2]--;
                tails[value + 3]++;
            } else {
                return false;
            }
            counter[value]--;
        }

        return true;
    }
};