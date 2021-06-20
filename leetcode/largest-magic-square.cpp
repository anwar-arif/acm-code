#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& rowsum, vector<vector<int>>& colsum) {
        int rows = (int) grid.size();
        int cols = (int) grid[0].size();
        
        int counter = 0, answer = 1;
        while (x + counter < rows && y + counter < cols) {
            int sum = rowsum[x][y + counter] - (y > 0 ? rowsum[x][y - 1] : 0);
            
            bool can = true;
            // row check
            for (int i = x; i <= x + counter; i++) {
                if (rowsum[i][y + counter] - (y > 0 ? rowsum[i][y - 1] : 0) != sum) {
                    can = false;
                    break;
                }
            }
            // col check
            for (int j = y; j <= y + counter; j++) {
                if (colsum[j][x + counter] - (x > 0 ? colsum[j][x - 1] : 0) != sum) {
                    can = false;
                    break;
                }
            }
            // diagonal check
            int firstDiag = 0, secondDiag = 0;
            for (int i = 0; i <= counter; i++) firstDiag += grid[x + i][y + i];
            for (int i = 0; i <= counter; i++) secondDiag += grid[x + i][y + counter - i];
            if (firstDiag != secondDiag) can = false;
            
            if (can) answer = counter + 1;
            
            counter += 1;
        }
        
        return answer;
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = (int) grid.size();
        if (rows == 0) return 0;
        
        int cols = (int) grid[0].size();
        vector<vector<int>> rowsum(rows + 1);
        vector<vector<int>> colsum(cols + 1);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0, sum = 0; j < cols; j++) {
                sum += grid[i][j];
                rowsum[i].push_back(sum);
            }
        }
        
        for (int j = 0; j < cols; j++) {
            for (int i = 0, sum = 0; i < rows; i++) {
                sum += grid[i][j];
                colsum[j].push_back(sum);
            }
        }
        
        int answer = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                answer = max(answer, solve(i, j, grid, rowsum, colsum));
            }
        }
        
        return answer;
    }
};

int main() {
    Solution sln;
    vector<vector<int>> grid = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    cout << sln.largestMagicSquare(grid) << endl;
}