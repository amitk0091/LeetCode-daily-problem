using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:

    // select all subsets of an array

    ll selectSubset(int n, vector<int>& coins, ll& value) {
        ll ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            ll lcm = 1, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    if (lcm == 0)
                        lcm = coins[i];
                    else
                        lcm = lcm * coins[i] / __gcd((ll)coins[i], lcm);
                }
            }
            if (cnt % 2) {
                ans += (value / lcm);
            } else {
                ans -= (value / lcm);
            }
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll low =1 , high = 1e18;
        while(low<=high){
            ll mid = (low+high)/2;
            if(selectSubset(coins.size(),coins,mid) >= (ll)k) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};