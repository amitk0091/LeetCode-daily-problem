class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
       sort(people.begin(),people.end());
       int n = people.size();
       vector<vector<int>> ans(n, vector<int> (2,-1));
       for(int i=0;i<n;i++){
          int cnt = people[i][1];
          int j=0;
          while(cnt>0){
            if(ans[j][0]==-1 || ans[j][0]>=people[i][0]) {
                cnt--;
            }
            j++;
          }
          while(ans[j][0]!=-1){
            j++;
          }
          ans[j][0] = people[i][0];
          ans[j][1] = people[i][1];
       } 
       return ans;
    }
};