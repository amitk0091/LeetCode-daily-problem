class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size()-2,vector<int>(grid.size()-2,0));
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid.size()-1;j++){
                int mx =0;
                for(int l =-1 ; l<=1;l++){
                    for(int h=-1;h<=1;h++){
                          mx= max(mx,grid[i+l][j+h]);
                    }
                }
                ans[i-1][j-1] = mx;
            }
        }
        return ans;
    }
};