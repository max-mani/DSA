class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int mh = 0;
        while (mh < 3) {
            int ch = 0;
            while (ch < 3) {
                vector<int>out(10, 0);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int row = i + 3 * ch, col = j + 3 * mh;
                        char c = board[row][col];
                        if (c != '.') {
                            int d = c - '0';
                            out[d]++;
                            if (out[d] > 1) return false;
                            for (int h = col + 1; h < 9; h++) {
                                if (c == board[row][h]) return false;
                            }        
                            for (int v = row + 1; v < 9; v++) {
                                if (c == board[v][col]) return false;
                            }            
                        }
                    }
                }
                ch++;
            }
            mh++;
        }
        return true;
    }
};