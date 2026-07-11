class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> out;
        for (int i = 0; i < s.size(); i++) {
            out[s[i]]++;
            out[t[i]]--;
        }
        for (int i = 'a'; i < 'z'; i++) {
            if (out[i] != 0) return false;
        }
        return true;
    }
};