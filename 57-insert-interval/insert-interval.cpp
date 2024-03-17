class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& nt) {
        vector<vector<int>> ans;
        // it.push_back(nt);
        // sort(it.begin(),it.end());
        // int start = it[0][0],end=it[1][0];
        // for(int i=1;i<it.size();i++){
        //    if(end<it[i][0]){
        //         ans.push_back({start,end});
        //      }
        //      start = it[i][0];
        //      end = it[i][1];
        //    }
        //    else end = max(end,it[i][1]);
        // }
        // ans.push_back({start,end});
        int i=0,n= it.size();
        while(i<n  && it[i][1]<nt[0]){
            ans.push_back(it[i]);
            i++;
        }
        while(i<n && it[i][0] <= nt[1]){
            nt[1] = max(nt[1],it[i][1]);
            nt[0] = min(nt[0],it[i][0]);
            i++;
        }
        ans.push_back(nt);
        while(i<n){
            ans.push_back(it[i]);
            i++;
        }
        return ans;
    }
};