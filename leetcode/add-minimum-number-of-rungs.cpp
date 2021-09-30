#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int answer = 0, pre = 0;
        for (int i = 0; i < (int) rungs.size(); i++) {
            answer += (rungs[i] - pre - 1) / dist;
            pre = rungs[i];
        }
        return answer;
    }
};

int main() {
    Solution sln;
    vector<vector<int>> rungs = {
        {1,3,5,10},
        {3,6,8,10},
        {3,4,6,7},
        {5}
    };
    vector<int> dist = {2, 3, 2, 10};
    vector<int> expected = {2, 0, 1, 0};

    for (int i = 0; i < (int) rungs.size(); i++) {
        cout << "Case# " << i << " " << ((sln.addRungs(rungs[i], dist[i]) == expected[i]) ? "Passed" : "Failed") << endl;
    }
}