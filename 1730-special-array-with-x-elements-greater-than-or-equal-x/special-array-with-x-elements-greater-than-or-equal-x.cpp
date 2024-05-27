class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums.size();
        int i = 0;
        while (x) {
            if (nums[i] >= x) {
                return x;
            } else if (nums[i] >= x - 1)
                return -1;
            x--;
            i++;
        }
        return -1;
    }
};