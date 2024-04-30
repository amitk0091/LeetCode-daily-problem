using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:

    // state 0 means we haven't start yet
    // state 1 means we have started picking
    // state 2 we have picked and terminated the subarray loop
    int dp[100001][3];
    int help(int i,int state,vector<int>& nums1, vector<int>& nums2){
        if(i==nums1.size()) return 0;
        if(dp[i][state]!=-1) return dp[i][state];
        if(state ==2 ) return dp[i][state]= nums1[i] + help(i+1,2,nums1,nums2);
        else if(state==1){
            // pick
            ll a = nums2[i] + help(i+1,1,nums1,nums2);
 
            // terminate
            ll b= nums1[i] + help(i+1,2,nums1,nums2);
            return dp[i][state]= max(a,b);
        }
        // start
        ll a = nums2[i] +  help(i+1,1,nums1,nums2);

        // not start
        ll b = nums1[i] +  help(i+1,0,nums1,nums2);
        return dp[i][state]= max(a,b);
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        fill_n(&dp[0][0],100001*3,-1);
        ll s1 =  help(0,0,nums1,nums2);
        fill_n(&dp[0][0],100001*3,-1);
        ll s2 = help(0,0,nums2,nums1);
       return max(s1,s2);
    }
};
