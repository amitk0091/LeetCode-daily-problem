class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
          int i=0,j=0;
          vector<vector<int>> ans(2);
          while(i<nums1.size() && j<nums2.size()){
               if(nums1[i] < nums2[j]){
                   if(i-1>=0 && nums1[i-1] == nums1[i]){
                    i++;
                    continue;
                   }
                   ans[0].push_back(nums1[i]);
                   i++;
               }
               else if(nums1[i] == nums2[j]) {
                i++;
                j++;
               }
               else{
                  if(j-1>=0 && nums2[j] == nums2[j-1]) {
                    j++;
                    continue;
                    }
                  ans[1].push_back(nums2[j]);
                  j++;
               }
          }
          while(j<nums2.size()){
             if(j-1>=0 && nums2[j] == nums2[j-1]) {
                    j++;
                    continue;
                    }
                  ans[1].push_back(nums2[j]);
                  j++;
          }
          while(i<nums1.size()){
            if(i-1>=0 && nums1[i-1] == nums1[i]){
                    i++;
                    continue;
                   }
                   ans[0].push_back(nums1[i]);
                   i++;
          }
          return ans;
    }
};