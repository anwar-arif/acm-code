#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        int length = (int) s.size();
        unordered_map<int, string> words;

        string cur = "";
        int counter = 0;

        for (int i = 0; i < length; i++) {
            if (s[i] == ' ') {
                int wordLength = (int) cur.size();
                if (wordLength) {
                    int id = cur[wordLength - 1] - '0';
                    cur.pop_back();
                    words[id] = cur;
                    counter++;
                }
                cur = "";
            } else {
                cur += s[i];
            }
        }
        int wordLength = (int) cur.size();
        if (wordLength) {
            int id = cur[wordLength - 1] - '0';
            cur.pop_back();
            words[id] = cur;
            counter++;
        }

        string answer = words[1];
        for (int i = 2; i <= counter; i++) {
            answer += " " + words[i];
        }

        return answer;
    }
};

int main() {
    Solution sln;
    string sentence = "is2 sentence4 This1 a3";
    cout << sln.sortSentence(sentence) << endl;
}