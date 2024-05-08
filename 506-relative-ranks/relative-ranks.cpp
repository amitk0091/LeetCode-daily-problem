class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // unordered_map<int, int> mp;
        // vector<int> s1=score;
        // sort(s1.begin(), s1.end(), greater<int>());
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < score.size(); i++) {
            // mp[s1[i]] = i;
            pq.push({score[i],i});
        }
        vector<string> st(score.size());
        for (int i = 0; i < score.size(); i++) {
            auto k = pq.top();
            pq.pop();
            if (i == 0) {
                st[k.second]="Gold Medal";
            } else if (i== 1) {
                st[k.second]="Silver Medal";
            } else if (i == 2) {
                st[k.second]="Bronze Medal";
            } else {
                st[k.second]= to_string(i+1);
            }
        }
        return st;
    }
};