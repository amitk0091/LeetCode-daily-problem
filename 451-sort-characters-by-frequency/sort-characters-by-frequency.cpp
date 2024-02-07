class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> freq(62);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                freq[s[i] - '0' + 52].first++;
                freq[s[i] - '0' + 52].second = s[i] - '0' + 52;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                freq[s[i] - 'A' + 26].first++;
                freq[s[i] - 'A' + 26].second = s[i] - 'A' + 26;
            } else {
                freq[s[i] - 'a'].first++;
                freq[s[i] - 'a'].second = s[i] - 'a';
            }
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());
        string res;
        for (int i = 0; i < 62; i++) {
            int k = freq[i].first;
            while (k--) {
                if(freq[i].second>=52){
                    res += '0' + freq[i].second - 52;
                }
                else if (freq[i].second >= 26) {
                    res += 'A' + freq[i].second - 26;
                }
                else {
                res += ('a' + freq[i].second);
                }
            }
        }
        return res;
    }
};