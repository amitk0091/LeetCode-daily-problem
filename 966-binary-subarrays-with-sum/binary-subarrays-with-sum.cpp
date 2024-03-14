class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> prefixZeroCnt(n);
        int cnt=0;
        m[0] =-1;
        int sum =0,ans=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           if(nums[i]==0) cnt++;
           else  cnt=0;
           prefixZeroCnt[i] = cnt;
           cout<<sum-target<<endl;
           if(m.find(sum - target) != m.end()){
             ans += 1+ (m[sum-target]==-1 ? 0: prefixZeroCnt[m[sum-target]]);
             cout<<"ans "<<ans<<endl;
           }
           m[sum] = i; 
        }
        return ans;
    }
};