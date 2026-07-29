class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>ind(numCourses, 0);
        for (auto& i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        int ch = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            ch++;
            for (int& i : adj[t]) {
                ind[i]--;
                if (ind[i] == 0) q.push(i);
            }
        }
        return ch == numCourses;
    }
};