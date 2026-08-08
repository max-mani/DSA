class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<int>& path, vector<int>& out, vector<vector<int>>& adj) {
        vis[i] = path[i] = 1;
        for (int j : adj[i]) {
            if (!vis[j]) {
                if (dfs(j, vis, path, out, adj)) {
                    return true;
                }
            } else if (path[j]) {
                return true;
            }
        }
        path[i] = 0;
        out.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0), path(n, 0), out;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, out, adj)) {
                    return {};
                }
            }
        }
        reverse(out.begin(), out.end());
        return out;
    }
};