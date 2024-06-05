
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        int freq[n][26];
        fill_n(&freq[0][0], n * 26, 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                freq[i][words[i][j] - 'a']++;
            }
        }
        int ofreq[26];
        fill_n(ofreq,26,INT_MAX);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                ofreq[j] = min(freq[i][j], ofreq[j]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            while (ofreq[i]--) {
                string s;
                s+=('a'+i);
                ans.push_back(s);
            }
        }
        return ans;
    }
};