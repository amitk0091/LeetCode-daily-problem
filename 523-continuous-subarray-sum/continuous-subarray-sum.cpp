class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<=1) return false;
         unordered_map<int,int> mp;
          int sum =0;
          mp[sum] = -1;
         for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && (i-1>=0 && nums[i-1]==0)) return true;
            else if(nums[i]==0) continue;
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()){
                cout<<i<<" "<<sum<<endl;
                if(i-mp[sum%k]>=2) return true;
            }
            else mp[sum%k] =i;
         }
         return false;
    }
};