#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int ALPHA = 26;
    int Id(char ch) {
        return ch - 'a';
    }
public:
    int countPalindromicSubsequence(string str) {
        int answer = 0, length = (int) str.size();

        vector<int> left(length, 0), right(length, 0);

        int mask = 0;
        for (int i = 0; i < length; i++) {
            left[i] = mask;
            mask |= (str[i] - 'a');
        }
        
        mask = 0;
        for (int j = length - 1; j >= 0; j--) {
            right[j] = mask;
            mask |= (str[j] - 'a');
        }

        unordered_map<string, int> exits;
        for (int i = 1; i < length - 1; i++) {
            for (int j = 0; j < ALPHA; j++) {
                bool pre = ((left[i - 1] >> j) & 1) > 0 ? 1 : 0;
                bool nxt = ((right[i + 1] >> j) & 1) > 0 ? 1 : 0;

                if (pre && nxt) {
                    string key = to_string('a' + j) + to_string(str[i]) + to_string('a' + j);
                    exits[key] = 1;
                }
            }
        }

        answer = (int) exits.size();

        return answer;
    }
};

int main() {
    Solution sln;
    cout << sln.countPalindromicSubsequence("aabca") << endl;
    cout << sln.countPalindromicSubsequence("adc") << endl;
    cout << sln.countPalindromicSubsequence("bbcbaba") << endl;
}