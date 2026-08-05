class Solution {
public:
    void dfs(int u, vector<int>& vis, vector<vector<int>>& adj) {
        vis[u] = 1;
        for (int j : adj[u]) {
            if (!vis[j]) dfs(j, vis, adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>vis(n, 0);
        vector<int>ans;
        vector<vector<int>>adj(n);
        for (auto& i : invocations) adj[i[0]].push_back(i[1]);
        dfs(k, vis, adj);
        for (auto& i : invocations) {
            if (!vis[i[0]] && vis[i[1]]) {
                for (int j = 0; j < n; j++) ans.push_back(j);
                return ans;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};