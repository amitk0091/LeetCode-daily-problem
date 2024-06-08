using ll = long long;
class Solution {
public:
    int dp[501][501][27];
    ll help(int i, int pick, int pre, vector<int>& nums){
        if(i==nums.size()) return 0;
         
        if(dp[i][pre+1][pick] != -1 ) return dp[i][pre+1][pick];
        ll a =0,b=0;
        
        // pick 
          if(pre!=-1 && nums[pre]==nums[i]){
              a = 1 + help(i+1,pick,i,nums);
          }
          else if(pick>0){
              a= 1 + help(i+1,pick-1,i,nums);
          }
          
        //not pick
         b = help(i+1,pick,pre,nums);
         // cout<<i<<" "<<pick<<" "<<pre<<endl;
        return  dp[i][pre+1][pick] = max(a,b);
    }
    int maximumLength(vector<int>& nums, int k) {
        fill_n(&dp[0][0][0], 501*501*27,-1);
        return help(0,k+1,-1,nums);
    }
};