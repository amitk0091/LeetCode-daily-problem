class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(2, vector<int>(2, -1));
        dp[0][0] = 0;
        dp[1][0] = 0;
        for (int i = 0; i < grid.size(); i++) {
            vector<vector<int>> aux(2, vector<int>(2, INT_MAX));

            for (int j = 0; j < grid[0].size(); j++) {
                int k = 0;
                if (dp[0][1] != j) {
                    k = dp[0][0];
                } else
                    k = dp[1][0];
                k += grid[i][j];
                if (aux[0][0] > k) {
                    aux[1] = aux[0];
                    aux[0] = {k, j};
                } else if (aux[1][0] > k) {
                    aux[1] = {k, j};
                }
            }
            dp = aux;
        }
        return dp[0][0];
    }
};