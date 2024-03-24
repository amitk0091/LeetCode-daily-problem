using ll = long long;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int  n = nums.size();

        int slow = nums[0];
        int fast = nums[0];

       // actually they are pointing to same so to avoid the condition first time we donot use fast
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);

        slow = nums[0];
        while(slow!=fast){
           slow = nums[slow];
            fast = nums[fast]; 
        }
        return slow;
        // int arr[100005]={0};
        // for(int i=0;i<n;i++){
        //     if(arr[nums[i]]>=1) return nums[i];
        //     arr[nums[i]]++;
        // }
        // return -1;

        // ll sum = accumulate(nums.begin(),nums.end(),0);
        // return (sum-n*(n-1)/2);


    }
};