#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        priority_queue<int> pool;
        int length = (int) quality.size();

        vector<int> ids(length);
        for (int i = 0; i < length; i++) ids[i] = i;
        
        sort(ids.begin(), ids.end(), [&](int i, int j){
            return wage[i] * quality[j] < wage[j] * quality[i];
        });

        double sum = 0.0, answer = (double) 1e18;
        for (int i = 0; i < length; i++) {
            int index = ids[i];

            if (pool.size() >= K) {
                auto top = pool.top(); pool.pop();
                sum -= top;
            }

            sum += quality[index];
            pool.push(quality[index]);

            if (pool.size() == K) {
                double ratio = (double) wage[index] / (double) quality[index];
                answer = min(answer, sum * ratio);
            }
        }

        return answer;
    }
};

int main() {
    Solution sln;
    vector<int> quality = {3,1,10,10,1};
    vector<int> wages = {4,8,2,2,7};
    int K = 3;

    cout << sln.mincostToHireWorkers(quality, wages, K) << endl;
}
/*
[3,1,10,10,1]
[4,8,2,2,7]
3
*/