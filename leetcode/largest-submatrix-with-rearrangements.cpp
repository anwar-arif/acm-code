class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int rows = (int) matrix.size();
        int cols = (int) matrix[0].size();
        vector<vector<int>> sum(rows, vector<int> (cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0) sum[i][j] = matrix[i][j] == 0 ? 0 : 1;
                else sum[i][j] = matrix[i][j] == 0 ? 0 : 1 + sum[i - 1][j];
            }
        }

        for (auto &row: sum) {
            sort(row.begin(), row.end());
        }

        int answer = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                answer = max(answer, (cols - j) * (sum[i][j]));
            }
        }

        return answer;
    }
};
