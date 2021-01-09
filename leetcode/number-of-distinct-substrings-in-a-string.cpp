/**
* @file number-of-distinct-substrings-in-a-string
* @author Anwar Hossain <anwararif727@gmail.com>
*
* @date Saturday December 26 2020
*
* @brief
*/
#include<bits/stdc++.h>
using namespace std; 

class Solution {
private:
    vector<vector<int>> trie;
public:
	int countDistinct(string s) {
		int len = (int) s.size();
		int answer = 0;
        trie.assign(len * len, vector<int>(26, 0));
        int nodeCount = 0;
		for (int i = 0; i < len; i++) {
            int current = 0;
			for (int j = i; j < len; j++) {
				int id = s[j] - 'a';
                if (trie[current][id] == 0) {
                    answer += 1;
                    trie[current][id] = ++nodeCount;
                }
                current = trie[current][id];
			}
		}
		return answer;
	}
};

int main() {
    Solution sln;
    string str = "ewjbqczenjpnisibwylxkdntoaqqfgdlufanzwgqonjnljlzfzlcgjnnusadxjoplcqhlxbuimdxuwmkaortbpibjvcnkdtfbjorulpvrcobavsqwhmblqfjsijacqkljmpkcotkjwjgturjeaxfhvdtnhsnnbwfigvtkrmxcsdfjwwdovitionqsdrtwmdecihdbgdhgukcizptboqashzbwfwilpikooqhoyoqngqadilnnsemudfdfitlujsafxjlwoeyiolyvjuuxkbqdqwiekedzmcnwcxmlcsfhayirnrfudbbnzujskivafgpppjrsfjdkypykyrlatthgzfsfrquirhbxvrticdlxgyvmubhpaebuaovanfvjxknseiswdqga";
    cout << (int) str.size() << endl;
    cout << sln.countDistinct(str) << endl;
    cout << "Time elasped: " << clock() << " ms" << endl;
}
