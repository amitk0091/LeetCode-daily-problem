class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& nt) {
        vector<vector<int>> ans;
        it.push_back(nt);
        sort(it.begin(),it.end());
        int start = -1,end=-1;
        for(int i=0;i<it.size();i++){
           if(end<it[i][0]){
             if(end!=-1){
                ans.push_back({start,end});
             }
             start = it[i][0];
             end = it[i][1];
           }
           else end = max(end,it[i][1]);

           if(i==it.size()-1){
            ans.push_back({start,end});
           }
        //    cout<<start<<" "<<end<<endl;
        }
        return ans;
    }
};