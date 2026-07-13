class Solution {
public:
    bool isValid(string s) {
        stack<char> out;
        unordered_map<char, char> ans;
        ans[')'] = '(';
        ans['}'] = '{';
        ans[']'] = '[';
        for (char i : s) {
            if (i == '(' || i == '{' || i == '[') {
                out.push(i);
            } else {
                if (out.empty() || out.top() != ans[i]) {
                    return false;
                }
                out.pop();
            }
        }
        return out.empty();
    }
};