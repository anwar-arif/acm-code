#include<bits/stdc++.h>
using namespace std;

class KMP {
public:
    string text = "";
    string pattern = "";
    vector<int> lps;

    KMP(string _text, string _pattern) {
        text = _text;
        pattern = _pattern;
        calculateLPS();
    }

    /* calculate longest prefix which is also a suffix*/
    void calculateLPS() {
        int len = (int) pattern.size();
        lps = vector<int> (len, 0);

        for (int i = 1, index = 0; i < len;) {
            if (pattern[i] == pattern[index]) {
                lps[i] = index + 1;
                i++, index++;
            } else {
                if (index != 0) {
                    index = lps[index - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> substrOccurrence() {
        vector<int> answer;

        int textLen = (int) text.size();
        int patternLen = (int) pattern.size();
        int i = 0, j = 0;

        while (i < textLen) {
            if (text[i] == pattern[j]) {
                i++, j++;
            }
            if (j == patternLen) {
                answer.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < textLen && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return answer;
    }
};

int main() {
    string text = "codeforces";
    string pattern = "e";

    KMP kmp(text, pattern);
    vector<int> positions = kmp.substrOccurrence();

    for (int pos: positions) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
/*
Time complexity O(textLen + patternLen)
*/
