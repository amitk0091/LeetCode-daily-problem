class Solution {
public:
    int dp[70][70][70] = {0};
    int help(int i, int j1, int j2, vector<vector<int>>& grid) {
        if (i == grid.size() || j1 < 0 || j2 < 0 || j1 >= grid[0].size() ||
            j2 >= grid[0].size())
            return 0;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans = 0;
        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                ans = max(ans, help(i + 1, j1 + k, j2 + l, grid));
            }
        }
        if (j1 == j2) {
            ans += grid[i][j1];
        } else {
            ans += grid[i][j1] + grid[i][j2];
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), -1);
        return help(0,0,grid[0].size()-1,grid);
    }
};