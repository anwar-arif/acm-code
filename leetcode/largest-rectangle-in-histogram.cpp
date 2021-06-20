#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int length = (int) heights.size();
        long long answer = 0;
        stack<int> stk;
        stk.push(-1);

        for (int i = 0; i < length; i++) {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) {
                int top = stk.top(); stk.pop();
                long long area = (long long) heights[top] * (long long) (i - stk.top() - 1);
                answer = max(answer, area);
            }
            stk.push(i);
        }

        while (stk.top() != -1) {
            int top = stk.top(); stk.pop();
            long long area = (long long) heights[top] * (length - stk.top() - 1);
            answer = max(answer, area);
        }
        
        return answer;
    }
};

int main() {
    Solution sln;
    vector<int> heights = {2,1,5,6,2,3};
    vector<int> heights1 = {2, 1, 2};
    cout << sln.largestRectangleArea(heights1) << endl;
}