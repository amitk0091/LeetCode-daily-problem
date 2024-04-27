using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    ll dp[201][201][2];
    ll help(ll one, ll zero, ll turn, ll limit) {
        if (one == 0 && zero == 0)
            return 1;
        if(dp[one][zero][turn] !=-1) return dp[one][zero][turn];
        ll cnt = 0;
        if (turn) {
            for (ll i = 1; i <= min(one, limit); i++) {
                cnt += help(one - i, zero, 0, limit);
                cnt%=MOD;
            }
        } else {
            for (ll i = 1; i <= min(zero, limit); i++) {
                cnt += help(one, zero - i,1, limit);
                cnt%=MOD;
            }
        }
        return dp[one][zero][turn]=cnt;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        fill_n(&dp[0][0][0],201*201*2,-1);
        ll a = help(one,zero,1,limit);
        ll b = help(one,zero,0,limit);
        return (a+b)%MOD;
    }
};