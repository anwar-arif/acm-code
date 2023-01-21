#include<bits/stdc++.h>
using namespace std;

void lcs(string &first, string &second) {
    int lenf = (int) first.size();
    int lens = (int) second.size();

    vector<vector<int>> dp(lenf + 1, vector<int>(lens + 1, 0));
    for (int i = 0; i <= lenf; i++) {
        for (int j = 0; j < lens; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int index = dp[lenf][lens];
    string answer;

    int i = lenf, j = lens;
    while (i > 0 && j > 0) {
        if (first[i - 1] == second[j - 1]) {
            answer += first[i - 1];
            i--, j--, index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(answer.begin(), answer.end());

    cout << "LCS: " << answer << ", Length: " << answer.size() << endl;
}

int main() {
    string first = "AGGTAB";
    string second = "GXTXAYB";

    lcs(first, second);
    return 0;
}
