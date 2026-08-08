class Solution {
public:
    vector<int> dfs(int i, int parent, vector<int>& ans, string& labels, vector<vector<int>>& adj) {
        vector<int> cnt(26, 0);
        for (int j : adj[i]) {
            if (j == parent) continue;
            vector<int> child = dfs(j, i, ans, labels, adj);
            for (int k = 0; k < 26; k++) {
                cnt[k] += child[k];
            }
        }
        ans[i] = ++cnt[labels[i] - 'a'];
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n);
        dfs(0, -1, ans, labels, adj);
        return ans;
    }
};