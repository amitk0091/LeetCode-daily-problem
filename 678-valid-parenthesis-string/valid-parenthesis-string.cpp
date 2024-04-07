class Solution {
public:
    map<pair<int, int>, bool> m;
    bool help(int i, int cnt, string& s) {
        if (i == s.length() && cnt == 0)
            return true;
        if (i == s.length() || cnt<0)
            return false;
        if (m.find({i, cnt}) != m.end())
            return m[{i, cnt}];
        bool a = false;
        if (s[i] == '*') {
            // taken '('
            a |= help(i + 1, cnt + 1, s);

            // taken as ')'
            a |= help(i + 1, cnt - 1, s);

            // taken as nothing
            a |= help(i + 1, cnt, s);
        } else {
            if (s[i] == '(')
                a |= help(i + 1, cnt + 1, s);
            else if (s[i] == ')')
                a |= help(i + 1, cnt - 1, s);
            else
                a |= help(i + 1, cnt, s);
        }
        m[{i, cnt}] = a;
        return a;
    }
    bool checkValidString(string s) { return help(0, 0, s); }
};