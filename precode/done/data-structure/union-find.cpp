#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> size;
    vector<int> parent;

    UnionFind(){}
    UnionFind(int n) {
        size = vector<int> (n + 1);
        parent = vector<int> (n + 1);

        for (int i = 0; i <= n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findpar(int r) {
        return (parent[r] == r) ? r : parent[r] = findpar(parent[r]);
    }

    bool unite(int x, int y) {
        int px = findpar(x);
        int py = findpar(y);

        if (px == py) return false;

        parent[px] = py;
        size[py] += size[px];
        return true;
    }
};

int main() {
    int n = 10;
    UnionFind uf(n);
    return 0;
}