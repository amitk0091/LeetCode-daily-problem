class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        int dp[26] = {0};
        fill_n(&dp[0], 26, -1);
        vector<int> right(s.length(), n);
        vector<int> left(s.length(), -1);
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int k = s[i] - 'A';
            left[i] = dp[k];
            dp[k] = i;
        }
        fill_n(dp, 26, s.length());
        for (int i = s.length()-1; i >=0; i--) {
            int k = s[i] - 'A';
            right[i] = dp[k];
            dp[k] = i;
        }

        for(int i=0;i<s.length();i++){
            ans+= ( i - left[i] )* (right[i] - i);
        } 
        return ans;
    }
};