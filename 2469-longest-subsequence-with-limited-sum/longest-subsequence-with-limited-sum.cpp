class Solution {
public:
    // int smaller_and_equal(vector<int> nums, int val){
    //     int low =0, high=nums.size()-1,ans=-1;
    //     while(low<=high){
    //         int mid = (low +high)/2;
    //         if(nums[mid]<= val ){
    //             ans = mid;
    //             low= mid+1;
    //         }
    //         else high = mid-1;
    //     }
    //     return ans;
    // }
    vector<int> answerQueries(vector<int>& nums, vector<int>& qs) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        vector<int> ans;
        for(auto q : qs){
        //    ans.push_back(smaller_and_equal(nums,q)+1);
        int k = upper_bound(nums.begin(),nums.end(),q) -nums.begin();
        ans.push_back(k);
        }
        return ans;
    }
};