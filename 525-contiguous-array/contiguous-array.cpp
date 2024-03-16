class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0]=-1;
        int n = nums.size(),ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]==0 ? -1:1);
            if(m.find(sum)!=m.end()){
                // cout<<sum<<" "<<
                ans = max(ans,i-m[sum]);
            }
            if(m.find(sum)==m.end()) m[sum] =i;
        }
        return ans;
    }
};