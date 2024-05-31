class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i-1>=0 && nums[i-1] == nums[i]) continue;
            else if(i+1<nums.size() && nums[i+1] == nums[i]) continue;
            ans.push_back(nums[i]);
        }
        return ans;
    }
};