class Solution {
public:
    bool isPalindrome(int x) {
        string st = to_string(x);
        int n = st.size();
        for (int i = 0; i < n / 2; i++) {
            if (st[i] != st[n - i - 1]) return false;
        }
        return true;
    }
};