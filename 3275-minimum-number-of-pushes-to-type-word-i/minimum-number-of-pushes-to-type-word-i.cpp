class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int out = n / 8;
        return (out * (out + 1) * 4) + ((n % 8) * (out + 1));
    }
};