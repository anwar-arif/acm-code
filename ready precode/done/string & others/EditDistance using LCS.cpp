#include <bits/stdc++.h>
using namespace std;

int editDistance(string& source, string& target) {
    int lens = (int) source.size();
    int lent = (int) target.size();

    vector<vector<int>> dp = vector<vector<int>> (lens + 1, vector <int> (lent + 1, 0));

    /** dp[i][j] = minimum operations to convert first i length of source to first j length of target*/

    for (int i = 0; i <= lens; i++) {
        for (int j = 0; j <= lent; j++) {
            /** insert j characters of target string*/
            if (i == 0) dp[i][j] = j;

            /** delete i characters of source string*/
            else if (j == 0) dp[i][j] = i;
            else {
                if (source[i - 1] == target[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min(
                                       dp[i][j - 1], /**insert*/
                                       min(dp[i - 1][j], /**delete*/
                                           dp[i - 1][j - 1])); /**replace*/
                }
            }
        }
    }

    return dp[lens][lent];
}

int main() {
    string a = "abcdef", b = "agced";
    cout << editDistance(a, b) << endl;
    return 0;
}
