class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(auto r : ranges){
            if(r[0]>right || r[1]<left) continue;
            if(r[0]<=left && right<=r[1]) return true;
            else if(r[0]<=left) left=r[1]+1;
            else right = r[0]-1;
        }
        return false;
    }
};