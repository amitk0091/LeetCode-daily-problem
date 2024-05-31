class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //     if(i-1>=0 && nums[i-1] == nums[i]) continue;
        //     else if(i+1<nums.size() && nums[i+1] == nums[i]) continue;
        //     ans.push_back(nums[i]);
        // }
        // return ans;

        int overAllXOR = 0;
        for (int& num : nums) {
            overAllXOR ^= num;
        }
        int bitPos = 0;
        while (((overAllXOR >> bitPos) & 1) == 0)
            bitPos++;

        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] >> bitPos) & 1) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return {a, b};
    }
};