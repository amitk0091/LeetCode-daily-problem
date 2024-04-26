using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        // why greedy will fail [272,482,115,925,983] 272 , 482 , 115+925+983
        //  int presm=-1;
        //  int cursm=0;
        //  int cnt=0;
        //  for(int i=0;i<n;i++){
        //     cursm +=nums[i];
        //     if(presm<=cursm){
        //       cnt++;
        //       presm=cursm;
        //       cursm=0;
        //     }
        //  }

        vector<ll> pref(n+1);
        pref[0] =0;
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]+nums[i];
        }

        vector<pair<ll,ll>> dp(n+2);
        dp[0].first =1 ;
        for(int i=1;i<=n;i++){
            dp[i] = max(dp[i],dp[i-1]);

            int idx = lower_bound(pref.begin(),pref.end(),2*pref[i] - dp[i].second) -pref.begin();

            dp[idx] = max(dp[idx],{dp[i].first+1,pref[i]});
        }
        return dp[n].first;
    }
};