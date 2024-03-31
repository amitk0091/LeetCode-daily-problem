class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
       long long ans=0;
       int min_ind=-1;
       int max_ind=-1;
       int start=-1;
       for(int i=0;i<nums.size();i++){
           if(nums[i]<mink || nums[i]>maxk){
               start=i;
               min_ind=-1;
               max_ind=-1;
           }
           else{
               if(nums[i]==mink) min_ind=i;
               if(nums[i]==maxk) max_ind=i;
               if(max_ind!=-1 && min_ind!=-1 ) ans+=min(min_ind,max_ind)-start;
           }
       }
       return ans;
    }
};