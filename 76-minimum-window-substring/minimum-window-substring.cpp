class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0;
        unordered_map<char, int> m1;
        for (char& ch : t)
            m1[ch]++;
        
        unordered_map<char, int> m2;
        int cnt = 0, ans = INT_MAX;
        pair<int, int> ind = {-1, -1};

        while (j < s.length()) {
            m2[s[j]]++;
            if (m1.find(s[j]) != m1.end() && m2[s[j]] == m1[s[j]])
                cnt++;
            if (cnt == m1.size()) {
                while (i < s.length() && (m1.find(s[i]) == m1.end() || m1[s[i]] < m2[s[i]])) {
                    m2[s[i]]--;
                    i++;
                }
                if (ans > (j - i + 1)) {
                    ans = j - i + 1;
                    ind = {i, j};
                }
                m2[s[i]]--;
                cnt--;
                i++;
            }
            j++;
        }
        return (ind.first == -1) ? "" : s.substr(ind.first, ans);
    }
};
