class Solution {
public:
    int cbin(int w, vector<pair<int,int>>& dp){
        int i=0,j=dp.size()-1,ind=-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(dp[mid].first<=w){
                 i = mid+1;
                 ind = max(ind, mid);
            }
            else{
                j = mid-1;
            }
        }
        return ind;
    }
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& ws) {
        int n = d.size();
        vector<pair<int,int>> dp(n);
        for(int i=0;i<n;i++){
             dp[i] = {d[i],p[i]};
        }
        sort(dp.begin(),dp.end());
        int pr = INT_MIN;
        for(int i=0;i<n;i++){
            pr = max(pr,dp[i].second);
            dp[i].second = pr;
        }
        int tp =0;
        for(int w : ws){
            int ind = cbin(w,dp);
            if(ind!=-1) tp+=dp[ind].second;
        }
    return tp;
    }
};