class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rec) {
        int n = rec.size();
        if(n==1) return true;

        map<pair<int,int>,int> mp;
        for(auto i:rec){
            mp[{i[0],i[1]}]++;
            mp[{i[2],i[3]}]++;
            mp[{i[2],i[1]}]--;
            mp[{i[0],i[3]}]--;
        }
        int points=0;
        for(auto& p : mp){
            if(abs(p.second)>1) return false;
            points+=abs(p.second);
        }
        return (points==4);
    }
};