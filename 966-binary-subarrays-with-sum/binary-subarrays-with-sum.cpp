class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> m;
        vector<int> prefixZeroCnt(n);
        int cnt=0;
        m[0] =-1;
        int sum =0,ans=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           cnt = (nums[i]==0 ? cnt+1 : 0);
           prefixZeroCnt[i] = cnt;
           if(m.find(sum - target) != m.end()){
             ans += 1+ (m[sum-target]==-1 ? 0: prefixZeroCnt[m[sum-target]]);
           }
           m[sum] = i; 
        }
        return ans;
    }
};