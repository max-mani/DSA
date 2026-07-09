class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i])) {
                if (mp[s[i]] != t[i]) {
                    return false;
                } 
            } else {
                for (auto& j : mp) {
                    if (j.second == t[i]) {
                        return false;
                    }
                }
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
};