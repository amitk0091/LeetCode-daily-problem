class NumArray {
public:
    vector<int> preAr;
    NumArray(vector<int>& nums) {
        preAr.resize(nums.size(),0);
        preAr[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            preAr[i] +=(nums[i]+preAr[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        return ( preAr[right] - (left==0? 0: preAr[left-1]));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */