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

        int cntStar=0,cnt=0,n =s.length();
        for(int i=0;i<n;i++){
           if(s[i]=='(' ) cnt++;
           else if(s[i]==')') cnt--;
           if(s[i]=='*') cntStar++;
           if(cnt<0 && cnt+cntStar<0) return false;
           else if (cnt<0){
            cntStar+=cnt;
            cnt=0;
           } 
        }

        cntStar=0,cnt=0;
        for(int i=n-1;i>=0;i--){
           if(s[i]=='(') cnt++;
           else if(s[i]==')') cnt--;
           if(s[i]=='*') cntStar++;
           if(cnt>0 && cnt-cntStar>0) return false;
           else if (cnt>0){
            cntStar-=cnt;
            cnt=0;
           } 
        }
        return true;

    }
};