class Solution {
public:
    int countSubstrings(string s) {
        // mcm
        int n = s.length();
        int totalCnt = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        totalCnt += n;
        for (int i = 1; i < n; i++) {
            int j = i, k = 0;
            while (j < n && k < n) {
                if (i == 1) {
                    if (s[j] == s[k]) {
                        dp[k][j] = 1;
                        totalCnt++;
                    }
                }
                else if(s[j] == s[k]) {
                    int aux = dp[k + 1][j - 1];
                    totalCnt += aux;
                    dp[k][j] = aux;
                }
                j++;
                k++;
            }
        }
        return totalCnt;
    }
};