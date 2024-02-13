class Solution {
public:
    vector<int> calc_lps(vector<int>& pattern) {
        vector<int> lps(pattern.size());
        int i = 0, j = 1;
        while (j < pattern.size()) {
            if (pattern[i] == pattern[j]) {
                i++;
                lps[j] = i;
                j++;
            } else {
                if (i == 0)
                    j++;
                else
                    i = lps[i - 1];
            }
        }
        // for(int i=0;i<lps.size();i++){
        //     cout<<lps[i]<<endl;
        // }
        return lps;
    }
    vector<int> Kmp(vector<int>& st, vector<int>& pattern) {
        vector<int> lps = calc_lps(pattern);
        // for(int i=0;i<st.size();i++){
        //     cout<<st[i]<<" ";
        // }
        vector<int> matches;
        int i = 0, j = 0;
        while (i < st.size()) {
            if (st[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == pattern.size()) {
                matches.push_back(i - j);
                j = lps[j - 1];
            } else if(i<st.size() && st[i]!=pattern[j]) {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return matches;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> st;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1])
                st.push_back(1);
            else if (nums[i] == nums[i + 1])
                st.push_back(0);
            else
                st.push_back(-1);
        }
        vector<int> matches = Kmp(st, pattern);
        return matches.size();
    }
};