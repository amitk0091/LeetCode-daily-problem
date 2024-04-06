class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        string ans;
        for (char& ch : s) {
            if (ch == '(') {
                cnt++;
            } else if (ch == ')') {
                cnt--;
            }
            if (cnt < 0) {
                cnt++;
                continue;
            }
            ans += ch;
        }
        string ans2;
        cnt=0;
        for (int i = ans.length() - 1; i >= 0; i--) {
            if (ans[i] == '(') {
                cnt++;
            } else if (ans[i] == ')') {
                cnt--;
            }
            if (cnt > 0) {
                cnt--;
                continue;
            }
            ans2 += ans[i];
        }
        reverse(ans2.begin(),ans2.end());
        return ans2;
    }
};