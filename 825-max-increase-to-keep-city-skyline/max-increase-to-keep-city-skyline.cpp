class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> xaxis(grid[0].size());
        vector<int> yaxis(grid.size());
        for (int i = 0; i < grid[0].size(); i++) {
            int heigh = INT_MIN;
            for (int j = 0; j < grid.size(); j++) {
                heigh = max(heigh, grid[j][i]);
            }
            xaxis[i]=heigh;
        }
        for (int i = 0; i < grid.size(); i++) {
            int heigh = INT_MIN;
            for (int j = 0; j < grid[0].size(); j++) {
                heigh = max(heigh, grid[i][j]);
            }
            yaxis[i] = heigh;
        }
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                   cout<<min(xaxis[j],yaxis[i])<<" ";
                   sum+= (min(xaxis[j],yaxis[i])-grid[i][j]);
            }
            cout<<endl;
        }
        return sum;
    }
};