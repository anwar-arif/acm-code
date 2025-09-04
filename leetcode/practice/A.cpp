#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
private:
    int islands;
    vector<int> parent;
    
public:
    UnionFind(int size) {
        parent.resize(size, -1);
        islands = 0;
    }

    void addLand(int x) {
        if (parent[x] >= 0) return;
        parent[x] = x;
        islands++;
    }

    bool isLand(int x) {
        return (parent[x] >= 0);
    }

    int getIslands() {
        return islands;
    }

    int findPar(int x) {
        return (parent[x] == x) ? x : parent[x] = findPar(parent[x]);
    }

    void unite(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);
        if (px <= py) {
            parent[px] = py;
        } else {
            parent[py] = px;
        }
    }
};

class Solution {
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, -1}};
public:
    vector<int> numIslands2(int rows, int cols, vector<vector<int>>& positions) {
        UnionFind uf(rows * cols);
        vector<int> answer;

        for (auto pos: positions) {
            int index = pos[0] * cols + pos[1];
            uf.addLand(index);

            for (auto dir: dirs) {
                int nr = pos[0] + dir.first;
                int nc = pos[1] + dir.second;
                int neighbour_index = nr * rows + nc;
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && uf.isLand(neighbour_index)) {
                    uf.unite(index, neighbour_index);
                }
            }

            answer.push_back(uf.getIslands());
        }

        return answer;
    }
};