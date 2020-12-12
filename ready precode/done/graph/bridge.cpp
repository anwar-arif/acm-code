#include<bits/stdc++.h>
using namespace std;

class Bridge {
private:
    int nodes, timer;
    vector<vector<int>> adj;
    vector<int> tin, low;
    vector<bool> visited;
    vector<pair<int, int>> bridges;
public:
    Bridge(int _nodes) {
        nodes = _nodes;
        timer = 0;

        adj.assign(nodes + 1, vector<int>());
        bridges.clear();

        tin.assign(nodes + 1, -1);
        low.assign(nodes + 1, -1);
        visited.assign(nodes + 1, false);
    }

    void addEdge(int from, int to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void dfs(int cur, int par = -1) {
        visited[cur] = true;
        tin[cur] = low[cur] = timer++;
        for (int to: adj[cur]) {
            if (to == par) continue;
            if (visited[to]) {
                low[cur] = min(low[cur], tin[to]);
            } else {
                dfs(to, cur);
                low[cur] = min(low[cur], low[to]);
                if (low[to] > low[cur]) {
                    bridges.push_back({cur, to});
                }
            }
        }
    }

    vector<pair<int, int>> getBridges() {
        for (int i = 1; i <= nodes; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return bridges;
    }
};

int main() {
//    freopen("in.txt", "r", stdin);

    int nodes, edges; scanf("%d %d", &nodes, &edges);
    Bridge bridge(nodes);

    for (int i = 0; i < edges; i++) {
        int from, to; scanf("%d %d", &from, &to);
        bridge.addEdge(from, to);
    }

    auto answer = bridge.getBridges();
    for (auto p: answer) {
        cout << p.first << " => " << p.second << endl;
    }
    return 0;
}
/*
complexity: O(V + E)
*/
