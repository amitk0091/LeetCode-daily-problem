class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(),cnt=0,sum=0;
        unordered_map<int,int> mp;
        mp[0] =1;
        for(int i=0;i<n;i++){
            sum = (sum + nums[i]%k +k) %k;
            cnt+=mp[sum%k];
            // cout<<mp[sum%k]<<endl;
            mp[sum%k]++;
        }
        return cnt;
    }
};