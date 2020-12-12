class Solution {
public:
    vector<bool> visited;
    vector<int> low, tin;
    vector<vector<int>> bridges, adj;
    int timer = 0;
    
    void dfs(int cur, int par) {
        visited[cur] = true;
        low[cur] = tin[cur] = timer++;
        for (int to: adj[cur]) {
            if (to == par) continue;
            if (visited[to]) {
                low[cur] = min(low[cur], tin[to]);
            } else {
                dfs(to, cur);
                low[cur] = min(low[cur], low[to]);
                if (low[to] > tin[cur]) {
                    bridges.push_back({cur, to});
                }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        timer = 0;
        visited.assign(n + 1, false);
        adj.assign(n + 1, vector<int>());
        low.assign(n + 1, -1);
        tin.assign(n + 1, -1);
        
        for (auto vec: connections) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i, -1);
            }
        }
        
        return bridges;
    }
};
