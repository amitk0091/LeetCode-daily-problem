class Solution {
public:
    char turnLeft(char ch) { return (ch == '0' ? '9' : ch - 1); }
    char turnRight(char ch) { return (ch == '9' ? '0' : ch + 1); }
    vector<string> generateNxtSteps(string st) {
        vector<string> nxt;
        for (int i = 0; i < 4; i++) {
            string temp = st;
            temp[i] = turnLeft(st[i]);
            nxt.push_back(temp);
            temp[i] = turnRight(st[i]);
            nxt.push_back(temp);
        }
        return nxt;
    }
    int openLock(vector<string>& dd, string target) {
        if(target=="0000") return 0;
        unordered_set<string> st(dd.begin(),dd.end());
        if(st.find("0000") != st.end()) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            vector<string> steps = generateNxtSteps(p.first);
            for(string step : steps){
                if(step==target) return p.second+1;
                if(st.find(step) == st.end()){
                  q.push({step,p.second+1});
                }
                st.insert(step);
            } 
        }
        return -1;
    }
};