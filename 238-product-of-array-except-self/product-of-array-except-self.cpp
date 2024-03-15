class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt0 =0;
        int n = nums.size();
        vector<int> ans(n);
        int prod = 1;
        for(int i=0;i<n;i++){
           if(nums[i]==0) cnt0++;
           else prod*=nums[i];
        }
        if(cnt0>=2) return ans;
        else if(cnt0==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0)  ans[i] = prod;
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            ans[i] = prod/nums[i];
        }
        return ans;
    }
};