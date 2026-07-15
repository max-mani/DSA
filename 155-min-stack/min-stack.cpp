class MinStack {
public:
    stack<pair<int, int>> out;
    void push(int value) {
        if (out.empty()) {
            out.push({value, value});
        } else {
            int t = min(value, out.top().second);
            out.push({value, t});
        }
    }
    void pop() {
        if (!out.empty()) out.pop();
    }
    
    int top() {
        return out.empty() ? -1 : out.top().first;
    }
    
    int getMin() {
        return out.empty() ? -1 : out.top().second;
    }
};