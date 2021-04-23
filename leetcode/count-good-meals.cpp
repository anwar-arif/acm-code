#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const long long mod = (long long) 1e9 + 7;
    const int M = 20;
public:
    int countPairs(vector<int> deliciousness) {
        long long answer = 0;
        unordered_map<long long, long long> count;

        for (auto value: deliciousness) {
            for (int i = 0; i <= M; i++) {
                answer += count[(1 << i) - value];
                answer %= mod;
            }

            count[value] += 1;
        }

        return answer;
    }
};

int main() {
    Solution sln;
    cout << sln.countPairs({1,1,1,3,3,3,7}) << endl;
}