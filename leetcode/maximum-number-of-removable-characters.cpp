#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool can(int limit, string &s, string &p, vector<int>& removable, vector<bool> &valid) {
        int lens = (int) s.size();
        int lenp = (int) p.size();
        int lenr = (int) removable.size();

        for (int i = 0, j = 0; i < lens; i++) {
            if (!valid[i] && i <= limit) continue;
            else if (s[i] == p[j]) {
                j++;
            }
            if (j == lenp) return true;
        }
        return false;
    }

public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lens = (int) s.size();
        int lenp = (int) p.size();
        int lenr = (int) removable.size();
        int answer = 0, lo = 0, hi = lenr - 1;
        
        vector<bool> valid(lens, true);
        for (int indx: removable) valid[indx] = false;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid, s, p, removable, valid)) {
                answer = mid + 1;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return answer;
    }
};

int main() {
    string s = "abcacb";
    string p = "ab";
    vector<int> removable = {3, 1, 0};

    Solution sln;
    cout << "answer: " << sln.maximumRemovals(s, p, removable) << endl;
}