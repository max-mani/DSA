class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size();
        int n = r * c;
        k %= n;
        if (!k) return grid;
        int i = 0, j = n - 1;
        while (i < j) {
            int temp = grid[i / c][i % c];
            grid[i / c][i % c] = grid[j / c][j % c];
            grid[j / c][j % c] = temp;
            i++;
            j--;
        }
        i = 0, j = k - 1;
        while (i < j) {
            int temp = grid[i / c][i % c];
            grid[i / c][i % c] = grid[j / c][j % c];
            grid[j / c][j % c] = temp;
            i++;
            j--;
        }
        i = k, j = n - 1;
        while (i < j) {
            int temp = grid[i / c][i % c];
            grid[i / c][i % c] = grid[j / c][j % c];
            grid[j / c][j % c] = temp;
            i++;
            j--;
        }
        return grid;
    }
};