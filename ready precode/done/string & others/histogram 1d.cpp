#include <bits/stdc++.h>
using namespace std;

int getHistogram(vector <int> &height) {
    int len = (int) height.size();
    stack <int> stk;
    stk.push(-1);
    int maxArea = 0;
    for (int i = 0; i < len; i++) {
        while (stk.top() != -1 && height[stk.top()] >= height[i]) {
            int top = stk.top(); stk.pop();
            int val = height[top];
            /// All heights between left(stk.top()) and right(i) are at least val
            maxArea = max(maxArea, val * (i - stk.top() - 1));
        }
        stk.push(i);
    }
    while (stk.top() != -1) {
        int top = stk.top(); stk.pop();
        int val = height[top];
        maxArea = max(maxArea, val * (len - stk.top() - 1));
    }
    return maxArea;
}

int main() {
    vector <int> height = vector <int> {1, 0, 2};
    cout << getHistogram(height) << endl;
}
