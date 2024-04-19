class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(int i, int j, vector<vector<char>>& grid){
        for(int k=0;k<4;k++){
            if(i+dx[k]>=0 && i+dx[k]<grid.size() && j+dy[k]>=0 && j+dy[k]<grid[0].size() && grid[i+dx[k]][j+dy[k]]=='1'){
                grid[i+dx[k]][j+dy[k]] ='0';
                dfs(i+dx[k],j+dy[k],grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};