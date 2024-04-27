class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int len=0;
        int area=0;
        for(auto d : dimensions){
            if(len< (d[0]*d[0] + d[1]*d[1])){
                area =d[0]*d[1];
                len =(d[0]*d[0] + d[1]*d[1]);
            }
            else if(len == (d[0]*d[0] + d[1]*d[1])) area = max(area,d[1]*d[0]);
        }
        return area;
    }
};