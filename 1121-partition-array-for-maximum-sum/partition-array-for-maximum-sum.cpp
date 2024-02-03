class Solution {
public:
    int help(int i, int k, vector<int>& arr,vector<int> &dp ){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mx=INT_MIN;
        int res=0;
        for(int j=i;j<=(i+(k-1)) && j<arr.size();j++){
            mx=max(mx,arr[j]);
            res = max(res,(j-i+1)*mx + help(j+1,k,arr,dp));
        }
        return dp[i]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return help(0,k,arr,dp);
    }
};