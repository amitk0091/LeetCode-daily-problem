class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mxFreq =0,cnt=0,ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            cnt++;
            if(i==nums.size()-1 || nums[i]!=nums[i+1]){
                if(cnt==mxFreq) ans+=cnt;
                else if(cnt>mxFreq) ans= cnt;
                mxFreq = max(mxFreq,cnt);
                cnt = 0;
            }
        }
        return ans;
        // map<int,int> m;
        // for(int& num : nums){
        //     m[num]++;
        //     mxFreq = max(mxFreq,m[num]);
        // }
        // int cnt=0;
        // for(auto [key,value] : m){
        //     if(value==mxFreq) cnt+=mxFreq;
        // }
        // return cnt;
    }
};