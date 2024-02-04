class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0;
        unordered_map<char, int> m1;
        
        // Initialize m1 with character frequencies from string t
        for (char& ch : t)
            m1[ch]++;
        
        unordered_map<char, int> m2;
        int cnt = 0, ans = INT_MAX;
        pair<int, int> ind = {-1, -1};

        while (j < s.length()) {
            m2[s[j]]++;

            // Check if the current character is in string t and its frequency is matched
            if (m1.find(s[j]) != m1.end() && m2[s[j]] == m1[s[j]])
                cnt++;

            // When all characters from t are found in the current window
            if (cnt == m1.size()) {
                // Contract the window from the left until the minimum window is reached
                while (i < s.length() && (m1.find(s[i]) == m1.end() || m1[s[i]] < m2[s[i]])) {
                    m2[s[i]]--;
                    i++;
                }

                // Update the minimum window size and indices
                if (ans > (j - i + 1)) {
                    ans = j - i + 1;
                    ind = {i, j};
                }

                // Move the left pointer and update the count
                m2[s[i]]--;
                cnt--;
                i++;
            }

            // Expand the window from the right
            j++;
        }

        // Return the minimum window substring
        return (ind.first == -1) ? "" : s.substr(ind.first, ans);
    }
};
