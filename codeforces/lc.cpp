#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
        int rows = (int) grid.size();
        int cols = (int) grid[0].size();
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == '1' && !visited[nr][nc]) {
                dfs(nr, nc, visited, grid);
            }
        }
    }
    

    int numIslands(vector<vector<char>>& grid) {
        int rows = (int) grid.size();
        if (rows == 0) return 0;
        int cols = (int) grid[0].size();
        
        int islands = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    islands += 1;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return islands;
    }
};

int main() {
    Solution sln;
    return 0;
}
