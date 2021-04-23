#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long mod = (int) 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = (int) arr.size();
        vector<int> prev(n), nxt(n);
        
        stack<int> stk;
        for (int i = 0 ; i < n; i++) {
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }
            prev[i] = (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                stk.pop();
            }
            nxt[i] = (stk.empty() ? n : stk.top());
            stk.push(i);
        }
        
        long long answer = 0;
        for (int i = 0; i < n; i++) {
            long long coef = (long long) (i - prev[i]) * (long long)(nxt[i] - i);
            long long total = (coef % mod) * (arr[i] % mod);
            
            answer += total;
            answer %= mod;
        }
        return answer;
    }
};

int main() {
    Solution sln;
    vector<int> arr = {3,1,2,4};
    cout << sln.sumSubarrayMins(arr) << endl;
}