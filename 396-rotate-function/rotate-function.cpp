class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n= nums.size();
        int sm= accumulate(nums.begin(),nums.end(),0);
        int tsm=0;
        for(int i=0;i<nums.size();i++) tsm += nums[i]*i;
        int ans=tsm;

        for(int i=0;i<n-1;i++){
            tsm = tsm -(sm-nums[i]) + (n-1)*nums[i];
            ans= max(ans,tsm);
        }
        return ans;
    }
};