#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int inf = (int) 1e9;
    string vowels = "aeiou";

    int getId(char ch) {
        for (int i = 0; i < (int) vowels.size(); i++) {
            if (ch == vowels[i]) return i;
        }
        return inf;
    }

    bool tryAdd(vector<int> &count, char ch) {
        int id = getId(ch);
        if (id == inf) return true;

        for (int i = id + 1; i < (int) vowels.size(); i++) {
            if (count[i]) return false;
        }

        count[id] += 1;
        return true;
    }

    bool valid(vector<int> &count) {
        for (int i = 0; i < (int) vowels.size(); i++) {
            if (count[i] == 0) return false;
        }
        return true;
    }

    int longestBeautifulSubstring(string word) {
        vector<int> count((int) vowels.size(), 0);

        int answer = 0, length = (int) word.size();
        for (int i = 0, hi = -1; i < length; i++) {
            while (hi + 1 < length && tryAdd(count, word[hi + 1])) {
                hi += 1;
            }
            if (valid(count)) {
                answer = max(answer, hi - i + 1);
            }
            count[getId(word[i])]--;
        }

        return answer;
    }
};

int main() {
    Solution sln;
    cout << sln.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu") << endl;
    cout << sln.longestBeautifulSubstring("aeeeiiiioooauuuaeiou") << endl;
    cout << sln.longestBeautifulSubstring("a") << endl;
}