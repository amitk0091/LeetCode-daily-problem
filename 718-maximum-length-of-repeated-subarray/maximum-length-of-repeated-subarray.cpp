class Solution {
public:
    // int help(int i, int j, string s1, string s2){
    //     if(i==s1.length() || j==s2.length()) return 0;
    //     if(s1[i]==s2[j]){
    //         return 1+help(i+1,j+1,s1,s2);
    //     }
    //     return max(help(i+1,j,s1,s2),help(i,j+1,s1,s2));
    // }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> pre(nums1.size()+1, 0);
        vector<int> curr(nums1.size()+1, 0);
        int ans=0;
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if(nums1[i]==nums2[j]){
                    curr[j] = 1 + pre[j+1];
                }
                else curr[j] =0;
                ans = max(ans,curr[j]);
            }
            pre=curr;
        }
        return ans;
    }
};