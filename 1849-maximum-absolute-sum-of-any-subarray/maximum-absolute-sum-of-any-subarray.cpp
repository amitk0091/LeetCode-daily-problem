class Solution {
public:
    int largestKadane(vector<int> arr){
        int sm=arr[0],res=arr[0];
        for(int i=1;i<arr.size();i++){
           sm+=arr[i];
           sm = max(arr[i],sm);
           res= max(res,sm);
        }
        return res;
    }
     int smallestKadane(vector<int> arr){
        int sm=arr[0],res=arr[0];
        for(int i=1;i<arr.size();i++){
           sm+=arr[i];
           sm = min(arr[i],sm);
           res= min(res,sm);
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(largestKadane(nums)),abs(smallestKadane(nums)));
    }
};