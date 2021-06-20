#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    const int dirs = 4;
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {1, 0, -1, 0};
    int rows, cols;
    
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& island, vector<vector<bool>>& visited) {
        island[x][y] = true;
        visited[x][y] = true;
        for (int i = 0; i < dirs; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny, grid, island, visited);
            }
        }
    }
    
    void isSubisland(int x, int y, bool &answer, vector<vector<int>>& grid, vector<vector<bool>>& island, vector<vector<bool>>& visited) {
        answer &= island[x][y];
        visited[x][y] = true;
        for (int i = 0; i < dirs; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1 && !visited[nx][ny]) {
                isSubisland(nx, ny, answer, grid, island, visited);
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = (int) grid1.size();
        if (rows == 0) return 0;
        cols = (int) grid1[0].size();
        
        vector<vector<bool>> island(rows, vector<bool>(cols, false));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid1[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, grid1, island, visited);
                }
            }
        }
        
        int subIslands = 0;
        visited = vector<vector<bool>> (rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    bool answer = true;
                    isSubisland(i, j, answer, grid2, island, visited);
                    subIslands += answer;
                }
            }
        }
        
        return subIslands;
    }
};