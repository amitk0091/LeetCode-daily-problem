class Solution {
public:
    int help(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];
        // if(i>=grid.size() || j>=grid[0].size())  this is not allowed as
        // restricted flow

        if (dp[i][j] != -1)
            return dp[i][j];

        int cost = INT_MAX;
        // possible 1
        if (i + 1 < grid.size()) {
            cost = help(i + 1, j, grid, dp);
        }
        // possible 2
        if (j + 1 < grid[0].size()) {
            cost = min(cost, help(i, j + 1, grid, dp));
        }
        return dp[i][j] = cost + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // Recursion and Backtracking if moving is allow in all direction
        // Recursion and Memoisation
        // tabulation n^2 TC and n^2 space

        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        // return help(0,0,grid,dp);

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int cost = INT_MAX;
                // possible 1
                if (i + 1 < grid.size()) {
                    cost = dp[i + 1][j];
                }
                // possible 2
                if (j + 1 < grid[0].size()) {
                    cost = min(cost, dp[i][j + 1]);
                }
                dp[i][j] = cost + grid[i][j];
            }
        }
        return dp[0][0];
    }
};