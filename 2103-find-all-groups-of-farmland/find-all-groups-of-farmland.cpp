class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    pair<int, int> dfs(int i, int j, vector<vector<int>>& grid) {
        if((i+1>=grid.size() || grid[i+1][j]==0) && (j+1>=grid[0].size() || grid[i][j+1]==0 )){
            grid[i][j] = 0;
            return {i, j};
        }
        int bi=i,bj=j;
        for (int k = 0; k < 4; k++) {
            if (i + dx[k] >= 0 && i + dx[k] < grid.size() && j + dy[k] >= 0 &&
                j + dy[k] < grid[0].size() && grid[i + dx[k]][j + dy[k]] == 1) {
                grid[i + dx[k]][j + dy[k]] = 0;
                auto p = dfs(i + dx[k], j + dy[k], grid);
                bi = max(bi, p.first);
                bj = max(bj, p.second);
            }
        }
        return {bi,bj};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    auto p = dfs(i,j,grid);
                    ans.push_back({i,j,p.first,p.second});
                }
            }
        }
        return ans;
    }
};