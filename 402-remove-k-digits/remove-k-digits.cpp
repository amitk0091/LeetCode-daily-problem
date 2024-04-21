class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length(), mn = INT_MAX;
        stack<char> st;
        int i = 0;
        for (i = 0; i < n; i++) {
            while (k > 0 && !st.empty() && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string temp;
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        string ans;
        for (char ch : temp) {
            if (ch == '0' && ans.length() == 0)
                continue;
            ans += ch;
        }
        return (ans.length() == 0 ? "0" : ans);
    }
};