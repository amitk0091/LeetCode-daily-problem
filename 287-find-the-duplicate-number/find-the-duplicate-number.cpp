using ll = long long;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int  n = nums.size();
        int arr[100005]={0};
        for(int i=0;i<n;i++){
            if(arr[nums[i]]>=1) return nums[i];
            arr[nums[i]]++;
        }
        return -1;

        // ll sum = accumulate(nums.begin(),nums.end(),0);
        // return (sum-n*(n-1)/2);


    }
};