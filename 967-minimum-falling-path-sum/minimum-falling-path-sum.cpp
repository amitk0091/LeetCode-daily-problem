class Solution {
public:
    int help(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        // base
        if (i == mat.size() - 1)
            return mat[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];
        int cost = INT_MAX;
        // possible 1
        if (i + 1 <= mat.size() - 1 && j - 1 >= 0) {
            cost = min(cost, help(i + 1, j - 1, mat, dp));
        }

        // possible 2
        if (i + 1 <= mat.size() - 1) {
            cost = min(cost, help(i + 1, j, mat, dp));
        }

        // possible 3
        if (i + 1 <= mat.size() - 1 && j + 1 <= mat[0].size() - 1) {
            cost = min(cost, help(i + 1, j + 1, mat, dp));
        }
        return dp[i][j] = cost + mat[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // Recursion TC = n.3^n+1 SC n stack space

        // Recursion memo n^2 , n^2
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // int ans = INT_MAX;
        // for (int i = 0; i < n; i++) {
        //     ans = min(ans,help(0, i, mat,dp));
        // }
        // return ans;

        // tabulation
        // vector<vector<int>> dp(m, vector<int>(n, 0));
           vector<int> prev(n,0);
           vector<int> curr(n,0);
        int ans = INT_MAX;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == mat.size() - 1)
                    curr[j] = mat[i][j];
                else {

                    int cost = INT_MAX;
                    // possible 1
                    if (i + 1 <= mat.size() - 1 && j - 1 >= 0) {
                        cost = min(cost, prev[j-1]);
                    }

                    // possible 2
                    if (i + 1 <= mat.size() - 1) {
                        cost = min(cost, prev[j]);
                    }

                    // possible 3
                    if (i + 1 <= mat.size() - 1 && j + 1 <= mat[0].size() - 1) {
                        cost = min(cost, prev[j + 1]);
                    }
                    curr[j] = cost + mat[i][j];
                }
                if (i == 0) {
                    ans = min(ans,curr[j]);
                }
            }
            prev = curr;
        }
        return ans;
    }
};