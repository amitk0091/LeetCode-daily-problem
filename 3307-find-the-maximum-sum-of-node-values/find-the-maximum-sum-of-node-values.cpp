using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        int n = nums.size(),cnt = 0,diff = INT_MAX;
        ll ans = 0;
        
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int b = nums[i] ^ k;
            if (a < b)
                cnt++;
            diff = min(diff, abs(b-a));
            ans += max(a,b);
        }
        if(cnt%2==1){
            ans -= diff;
        }
        return ans;
    }
};