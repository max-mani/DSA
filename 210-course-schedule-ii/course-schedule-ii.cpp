class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>out, ind(n, 0);
        priority_queue<int, vector<int>, greater<int>>q;
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int c = q.top();
            out.push_back(c);
            q.pop();
            for (int i : adj[c]) {
                ind[i]--;
                if (ind[i] == 0) q.push(i);
            }
        }
        if (out.size() != n) return {};
        return out;
    }
};