/**
 * @file change-minimum-characters-to-satisfy-one-of-three-conditions
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Tuesday January 26 2021
 *
 * @brief 
 */
class Solution {
public:
    const int inf = (int) 2e9;
    const int alpha = 26;

    int solve(string &a, string &b) {
        int lena = (int) a.size();
        int lenb = (int) b.size();

        vector<int> countA(alpha, 0), countB(alpha, 0);
        for (auto ch: a) countA[ch - 'a']++;
        for (auto ch: b) countB[ch - 'a']++;

        int answer = inf;
        for (int i = 0; i < alpha; i++) {
            int common = lena + lenb - countA[i] - countB[i];
            answer = min(answer, common);
            if (i > 0) {
                countA[i] += countA[i - 1];
                countB[i] += countB[i - 1];
            }
            if (i < alpha - 1) {
                int opt1 = lena - countA[i] + countB[i];
                int opt2 = lenb - countB[i] + countA[i];
                answer = min(answer, min(opt1, opt2));
            }
        }
        return answer;        
    }

    int minCharacters(string a, string b) {
        return solve(a, b);            
    }
};
