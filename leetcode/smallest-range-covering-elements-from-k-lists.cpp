class Solution {
public:
    const int inf = (int) 2e9;
    
    int globalCounter = 0;
    vector<int> counter;
    
    void add(int index) {
        counter[index] += 1;
        if (counter[index] == 1) globalCounter += 1;
    }
    
    void del(int index) {
        counter[index] -= 1;
        if (counter[index] == 0) globalCounter -= 1;
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> arr;
        int n = 0, k = (int) nums.size();
        
        for (int i = 0; i < k; i++) {
            for (int value: nums[i]) {
                arr.push_back({value, i});
                n += 1;
            }
        }
        
        counter.assign(k + 1, 0);
        sort(arr.begin(), arr.end());
        
        int answer = inf, starting = 0;
        for (int i = 0, hi = -1; i < n; i++) {
            while (hi + 1 < n && globalCounter < k) {
                hi += 1;
                add(arr[hi].second);
            }
            if (globalCounter == k) {
                if (answer > (arr[hi].first - arr[i].first)) {
                    answer = arr[hi].first - arr[i].first;
                    starting = arr[i].first;
                }
            }
            del(arr[i].second);
        }
        return {starting, starting + answer};
    }
};
