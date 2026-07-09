class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9 +7;
        int n = s.size();
        vector<int> su(n + 1, 0);
        vector<int> pr(n + 1, 0);
        vector<int> cn(n + 1, 0);
        vector<int> out;
        vector<long long> p(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * 10 % mod;
        }
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            su[i + 1] = su[i] + d;
            if (d) {
                pr[i + 1] = (pr[i] * 10LL + d) % mod;
                cn[i + 1] = cn[i] + 1;
            } else {
                pr[i + 1] = pr[i];
                cn[i + 1] = cn[i];
            }
        }
        for (auto& i : queries) {
            int l = i[0], r = i[1] + 1;
            long long t = pr[l] * p[cn[r] - cn[l]] % mod;
            long long x = (pr[r] - t + mod) % mod;
            out.push_back(x * (su[r] - su[l]) % mod);
        }
        return out;
    }
};