class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sm = 0, tsm = 0;
        for (int i = 0; i < nums.size(); i++) {
            sm += nums[i];
            tsm += nums[i] * i;
        }
        int ans = tsm;
        for (int i = 0; i < n - 1; i++) {
            tsm = tsm - (sm - nums[i]) + (n - 1) * nums[i];
            ans = max(ans, tsm);
        }
        return ans;
    }
};