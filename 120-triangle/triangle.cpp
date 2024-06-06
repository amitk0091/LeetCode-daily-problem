class Solution {
public:
    int help(int i, int j, vector<vector<int>>& t,vector<vector<int>>& dp){
        if(i==t.size()-1) return t[i][j];
      
        if(dp[i][j] !=-1) return dp[i][j];

        int cost = INT_MAX;
        // constrained flow
        if(i+1<t.size()){
          cost = min(cost, help(i+1,j,t,dp));
        }
        if(i+1<t.size() && j+1<i+2){
          cost = min(cost, help(i+1,j+1,t,dp));
        }
        return dp[i][j] =  cost + t[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // recursion + 2^n TC O(n) recursion stack space

        // recursion and momo total number of cells 1 2 3 n n(n+1)/2 
        int n = triangle.size();
         vector<vector<int>> dp(n,vector<int>(n,-1));
         return help(0,0,triangle,dp);
        // tabulation 

    }
};