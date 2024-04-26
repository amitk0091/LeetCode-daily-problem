class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int> m;
        int mx = 0, mn = INT_MAX;
        int j = 0,ans=1;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
            mx = max(nums[i], mx);
            mn = min(nums[i], mn);
            while (j<=i && mx - mn > limit) {
                m[nums[j]]--;
                if (m[nums[j]] == 0)
                    m.erase(nums[j]);
                mn = m.begin()->first;
                mx = m.rbegin()->first;
                j++;
            }
            ans = max(ans,(i-j+1));
        }
        return ans;
    }
};