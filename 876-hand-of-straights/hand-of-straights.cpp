class Solution {
public:
    bool isNStraightHand(vector<int>& h, int gs) {
        int n = h.size();
        if(n%gs) return false;
        int cn = n/gs;
        vector<pair<int,int>> container(cn,{-1,0});
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[h[i]]++;
        }

        for(auto p : m){
            int num = p.first;
            int cnt = p.second;
            int i=0;
            while(i<cn && cnt>0){
                if(container[i].second == gs) {
                    i++;
                    continue;
                }
               if(container[i].first!=-1 && container[i].first!=num-1) return false;
               container[i].first = num;
               container[i].second++;
               cnt--;
               i++;
            }
            if(cnt) return false;
        }
        return true;
    }
};