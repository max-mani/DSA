class Solution {
public:
    int calculate(string s) {
        long long int out = 0;
        int sign = 1;
        stack<pair<int, int>> st;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                long long int n = 0;
                while (i < s.size() && isdigit(s[i])) {
                    n = n * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                out += n * sign;
                sign = 1;
            } else if (s[i] == '(') {
                st.push({out, sign});
                out = 0;
                sign = 1;
            } else if (s[i] == ')') {
                out = st.top().first + (st.top().second * out);
                st.pop();
                sign = 1;
            } else if (s[i] == '-') {
                sign *= -1;
            }
        }
        return out;
    }
};