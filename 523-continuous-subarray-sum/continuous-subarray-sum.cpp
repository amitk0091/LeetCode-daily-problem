class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         unordered_map<int,int> mp;
          int sum =0;
          mp[sum] = -1;
         for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()){
                if(i-mp[sum%k]>=2) return true;
            }
            else mp[sum%k] =i;
         }
         return false;
    }
};