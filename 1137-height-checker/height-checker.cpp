class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> w(h.begin(),h.end());
        sort(w.begin(),w.end());
        int cnt=0;
        for(int i=0;i<h.size();i++){
            if(h[i] != w[i]) cnt++;
        }
        return cnt;
    }
};