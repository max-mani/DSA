class Solution {
public:
    int minimumPushes(string word) {
        return (((word.size()) / 8) * (((word.size()) / 8) + 1) * 4) + (((word.size()) % 8) * (((word.size()) / 8) + 1));
    }
};