class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>board_lives(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (i > 0 && j > 0) if (board[i - 1][j - 1]) board_lives[i][j]++;
                if (i > 0) if (board[i - 1][j]) board_lives[i][j]++;
                if (i > 0 && j + 1 < board[0].size()) if (board[i - 1][j + 1]) board_lives[i][j]++;
                if (j > 0) if (board[i][j - 1]) board_lives[i][j]++;
                if (j + 1 < board[0].size()) if (board[i][j + 1]) board_lives[i][j]++;
                if (i + 1 < board.size() && j > 0) if (board[i + 1][j - 1]) board_lives[i][j]++;
                if (i + 1 < board.size()) if (board[i + 1][j]) board_lives[i][j]++;
                if (i + 1 < board.size() && j + 1 < board[0].size()) if (board[i + 1][j + 1]) board_lives[i][j]++;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j]) {
                    if (board_lives[i][j] == 2 or board_lives[i][j] == 3) board[i][j] = 1;
                    else board[i][j] = 0;
                } else {
                    if (board_lives[i][j] == 3) board[i][j] = 1;
                    else board[i][j] = 0;
                }
            }
        }
    }
};