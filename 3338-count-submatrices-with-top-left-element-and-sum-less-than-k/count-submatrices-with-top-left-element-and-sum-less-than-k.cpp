class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            int pre=0;
            for(int j=0;j<grid[0].size();j++){
                int a = (i-1>=0 ? grid[i-1][j]:0);
                 int aux = pre+a;
                 pre += grid[i][j];
                 grid[i][j]+= aux;
                // cout<<grid[i][j]<<" ";
                 if(grid[i][j]<=k) cnt++;
            }
            // cout<<endl;
        }
        return cnt;
    }
};