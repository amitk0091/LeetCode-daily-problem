class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int mxFreq =0;
        for(int& num : nums){
            m[num]++;
            mxFreq = max(mxFreq,m[num]);
        }
        int cnt=0;
        for(auto [key,value] : m){
            if(value==mxFreq) cnt+=mxFreq;
        }
        return cnt;
    }
};