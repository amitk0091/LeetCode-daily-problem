using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    bool fun(ll mid, int& orders, vector<int>& in) {
        ll balls = 0;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] > mid)
                balls += (in[i] - mid);
        }
        return (balls>=orders);
    }
    int maxProfit(vector<int>& in, int orders) {

        ll low = 0, high = *max_element(in.begin(), in.end());
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (fun(mid, orders, in)) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        ll res = 0;
        cout<<low<<endl;
        for (long long i : in) {
            if (i > low) {
                res += (i - low) * (i + low + 1LL) / 2;
                res %= MOD;
                orders -= (i - low);
                orders = max(0, orders);
            }
        }
        return (res + low * orders) % MOD;
    }
};