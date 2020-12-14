class Solution {
public:
    void backtrack(int cur, int target, vector<int> path, vector<vector<int>> &answer, vector<vector<int>> &adj) {
        if (cur == target) {
            answer.push_back(path);
            return;
        }
        
        for (int child: adj[cur]) {
            path.push_back(child);
            backtrack(child, target, path, answer, adj);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> answer;
        int n = (int) graph.size();
        vector<vector<int>> adj(n, vector<int>());
        
        for (int from = 0; from < n; from++) {
            for (int to: graph[from]) {
                adj[from].push_back(to);
            }
        }
        
        vector<int> path = {0};
        backtrack(0, n - 1, path, answer, adj);
        
        return answer;
    }
};
