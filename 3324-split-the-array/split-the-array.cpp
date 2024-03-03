class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num : nums) m[num]++;
        for(auto & [k,v] : m){
            if(v >2) return false;
        }
        return true;
    }
};