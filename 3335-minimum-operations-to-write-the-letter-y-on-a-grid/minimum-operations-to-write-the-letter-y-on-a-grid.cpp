class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int cnty[3] ={0};
        int remain[3] ={0};
        int n = grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==j && i<=n/2){
                    cnty[grid[i][j]]++;
                }
                else if(i==(n-1-j) && i<=n/2){
                    cnty[grid[i][j]]++;
                }
                else if(i>n/2 && j==n/2) cnty[grid[i][j]]++;
                else remain[grid[i][j]]++;
            }
            
        }
        
        int op =INT_MAX;
        // 0 // 1
        op = min(cnty[1]+cnty[2] + remain[0]+ remain[2] , op); 
        
        //0 2
        op = min(cnty[1]+cnty[2] + remain[0]+ remain[1] , op);
        
        // 1 0 
        op = min(cnty[0]+cnty[2] + remain[1]+ remain[2] , op);
        
        // 1 2
        op = min(cnty[0]+cnty[2] + remain[0]+ remain[1] , op);  
        
        // 2 0 
        op = min(cnty[0]+cnty[1] + remain[2]+ remain[1] , op);
        
        // 2 1
        op = min(cnty[0]+cnty[1] + remain[0]+ remain[2] , op);

        return op;
    }
};