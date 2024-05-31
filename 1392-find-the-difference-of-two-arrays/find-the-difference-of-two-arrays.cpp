class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        set<int> st11;
        set<int> st22;
        for(int i=0;i<nums1.size();i++){
            if(st2.find(nums1[i]) == st2.end()) st11.insert(nums1[i]);
        }
         for(int i=0;i<nums2.size();i++){
            if(st1.find(nums2[i]) == st1.end()) st22.insert(nums2[i]);
        }
        vector<int> a(st11.begin(),st11.end());
        vector<int> b(st22.begin(),st22.end());
        return {a,b};
    }
};