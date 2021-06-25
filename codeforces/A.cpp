#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

bool isValid(int from, int to, map<pair<int, int>, bool> &has, map<pair<int, int>, int> &count, int required) {
    pair<int, int> couple = {from, to};
    return (has[couple] && (count[couple] == required));
}

int solve(vector<vector<int>> &A) {
    int rows = (int) A.size();
    if (rows == 0) return 0;
    int cols = (int) A[0].size();

    map<pair<int, int>, bool> has;
    map<pair<int, int>, int> count;

    for (int i = 0; i < cols - 1; i++) {
        int from = A[0][i], to = A[0][i + 1];
        pair<int, int> couple = {from, to};
        has[couple] = true;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            int from = A[i][j], to = A[i][j + 1];
            pair<int, int> couple = {from, to};
            if (has[couple]) count[couple] += 1;
        }
    }

    int longest = 0;
    for (int i = 0; i < cols - 1; i++) {
        int current = 0;
        while (i < cols - 1 && isValid(A[0][i], A[0][i + 1], has, count, rows)) {
            current += 1;
            i++;
        }
        longest = max(longest, current);
    }

    return longest + 1;
}

int main() {
    vector<vector<int>> arr = {
        {1,2,3,4},
        {3,4,1,2},
        {3,1,2,4}
    };

    cout << solve(arr) << endl;
    return 0;
}

/*

{
    {1,2,3,4},
    {3,4,1,2},
    {3,1,2,4}
}

*/
