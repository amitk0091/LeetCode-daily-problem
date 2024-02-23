class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // int s = 1e6+3;
        int dp[int(1e6+3)]={0};
        int ans=1;
        for(int i=nums.size()-1;i>=0;i--){
            dp[nums[i]] =1+dp[nums[i]+1] ;
            dp[nums[i]+1] = 1+dp[nums[i]+2];
           int mx = max(dp[nums[i]],dp[nums[i]+1]);
           ans= max(ans,mx);
        }
        return ans;
    }
};