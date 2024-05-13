using ll = long long;
class Solution {
public:
    ll powerOFTwo(ll base, ll power) {
        ll result = 1;
        while (power > 0) {
            if (power % 2) {
                result *= base;
            }
            base *= base;
            power /= 2;
        }
        return result;
    }
    int matrixScore(vector<vector<int>>& grid) {
        ll sm = 0;
        for (ll i = 0; i < grid.size(); i++) {
            sm += powerOFTwo(2, grid[0].size() - 1);
            if (grid[i][0] == 1)
                continue;
            for (ll j = 0; j < grid[0].size(); j++) {
                grid[i][j] ^= 1;
            }
        }
        for (ll i = 1; i < grid[0].size(); i++) {
            ll cnt = 0;
            for (ll j = 0; j < grid.size(); j++) {
                cnt += grid[j][i];
            }
            sm += max(cnt, (ll)grid.size() - cnt) *
                  powerOFTwo(2, (ll)(grid[0].size() - i - 1));
        }
        return sm;
    }
};