class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       int n = nums.size();
       for(int i=0;i<(1<<n);i++){
           vector<int> aux;
           int k=i;
           int cnt=0;
           while(k>0){
            if(k & 1){
               aux.push_back(nums[cnt]);
            }
            k=(k>>1);
            cnt++;
           }
           ans.push_back(aux);
       } 
       return ans;
    }
};