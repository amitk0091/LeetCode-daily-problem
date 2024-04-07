class Solution {
public:
    // map<pair<int, int>, bool> m;
    // bool help(int i, int cnt, string& s) {
    //     if (i == s.length() && cnt == 0)
    //         return true;
    //     if (i == s.length() || cnt<0)
    //         return false;
    //     if (m.find({i, cnt}) != m.end())
    //         return m[{i, cnt}];
    //     bool a = false;
    //     if (s[i] == '*') {
    //         // taken '('
    //         a |= help(i + 1, cnt + 1, s);

    //         // taken as ')'
    //         a |= help(i + 1, cnt - 1, s);

    //         // taken as nothing
    //         a |= help(i + 1, cnt, s);
    //     } else {
    //         if (s[i] == '(')
    //             a |= help(i + 1, cnt + 1, s);
    //         else if (s[i] == ')')
    //             a |= help(i + 1, cnt - 1, s);
    //         else
    //             a |= help(i + 1, cnt, s);
    //     }
    //     m[{i, cnt}] = a;
    //     return a;
    // }
    bool checkValidString(string s) {
        //  return help(0, 0, s); 

        int cntClose=0,cnt=0,n =s.length();
        for(int i=0;i<n;i++){
           if(s[i]=='(' || s[i]=='*'  ) cnt++;
           else if(s[i]==')') cnt--;
            int j = n-1-i;
           if(s[j]==')' || s[j]=='*') cntClose++;
           else if(s[j]=='(') cntClose--;
 
           if(cnt<0 || cntClose<0) return false;
        }
        return true;

    }
};