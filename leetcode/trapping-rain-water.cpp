#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int len = (int) height.size();
        int left = 0, right = len - 1, answer = 0;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                (leftMax < height[left]) ? leftMax = height[left] : answer += leftMax - height[left];
                left++;
            } else {
                (rightMax < height[right] ? rightMax = height[right] : answer += rightMax - height[right]);
                right--;
            }
        }
        return answer;
    }
};


int main() {
    Solution sln;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sln.trap(height) << endl;
    return 0;
}
