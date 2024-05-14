class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int aux = 0;
        int temp = grid[i][j];
        grid[i][j]=0;
        for (int k = 0; k < 4; k++) {
            if (i + dx[k] >= 0 && i + dx[k] < grid.size() && j + dy[k] >= 0 &&
                j + dy[k] < grid[0].size() && grid[i + dx[k]][j + dy[k]] > 0) {
                aux = max(aux, dfs(i + dx[k], j + dy[k], grid));
            }
        }
        grid[i][j] = temp;
        return aux+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        // recursion backtracking
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};