using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int limit =2;
        int n = nums.size();
        deque<int> dqmx, dqmn;
        ll j = 0, ans = 0,cnt=0;
        for (int i = 0; i < n; i++) {
            while (!dqmx.empty() && dqmx.back() < nums[i])
                dqmx.pop_back();
            while (!dqmn.empty() && dqmn.back() > nums[i])
                dqmn.pop_back();

            dqmx.push_back(nums[i]);
            dqmn.push_back(nums[i]);
            cnt++;
            int mx = dqmx.front();
            int mn = dqmn.front();
            while (j <= i && mx - mn > limit) {
                if (nums[j] == dqmx.front())
                    dqmx.pop_front();
                if (nums[j] == dqmn.front())
                    dqmn.pop_front();
                mx = dqmx.front();
                mn = dqmn.front();
                j++;
                cnt--;
            }
            ans +=cnt;
        }
        return ans;
    }
};