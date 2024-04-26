class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // not circular then kadane's
        int sum=nums[0];
        int mxsm =nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            sum=max(sum,nums[i]);
            mxsm = max(sum,mxsm);
        }

        sum=nums[0];
        int mnsm =nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            cnt++;
            if(sum>=nums[i]) cnt=1;
            sum=min(sum,nums[i]);
            mnsm = min(sum,mnsm);
        }

        // totalsm
        cout<<mxsm<<" "<<mnsm<<endl;
        sum = accumulate(nums.begin(),nums.end(),0);
        return max(mxsm,(cnt==nums.size() ? mnsm:sum-mnsm));
    }
};