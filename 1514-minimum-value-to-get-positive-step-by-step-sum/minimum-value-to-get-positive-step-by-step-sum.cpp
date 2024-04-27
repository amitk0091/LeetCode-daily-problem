class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int start = 1;
        int ans = 1;
        for (auto num : nums) {
            start += num;
            if (start <= 0) {
                ans += -start + 1;
                start=1;
            }
        }
        return ans;
    }
};