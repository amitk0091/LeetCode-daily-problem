class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> mp;
        vector<int> s1=score;
        sort(s1.begin(), s1.end(), greater<int>());
        for (int i = 0; i < score.size(); i++) {
            mp[s1[i]] = i;
        }
        vector<string> st;
        for (int i = 0; i < score.size(); i++) {
            if (mp[score[i]] == 0) {
                st.push_back("Gold Medal");
            } else if (mp[score[i]] == 1) {
                st.push_back("Silver Medal");
            } else if (mp[score[i]] == 2) {
                st.push_back("Bronze Medal");
            } else {
                st.push_back(to_string(mp[score[i]]+1));
            }
        }
        return st;
    }
};