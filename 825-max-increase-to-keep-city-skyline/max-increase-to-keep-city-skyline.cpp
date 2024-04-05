class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> xaxis(grid[0].size(),INT_MIN);
        vector<int> yaxis(grid.size(),INT_MIN);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                xaxis[j] = max(xaxis[j],grid[i][j]);
                yaxis[i] = max(yaxis[i],grid[i][j]);
            }
        }
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                   sum+= (min(xaxis[j],yaxis[i])-grid[i][j]);
            }
        }
        return sum;
    }
};