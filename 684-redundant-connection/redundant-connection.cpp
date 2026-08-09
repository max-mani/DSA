class Solution {
public:
    vector<int> par, rank;

    int find(int n) {
        int p = par[n];
        while (p != par[p]) p = par[par[p]];
        return p;
    }

    bool unin(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) {
            par[p2] = par[p1];
            rank[p1] += rank[p2];
        } else {
            par[p1] = par[p2];
            rank[p2] += rank[p1];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n + 1);
        rank.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) par[i] = i;
        for (auto& it : edges) {
            int n1 = it[0], n2 = it[1];
            if (!unin(n1, n2)) return {n1, n2};
        }
        return {};
    }
};