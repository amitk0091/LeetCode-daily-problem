class Solution {
public:
    bool isSubsequence(string s, string t) {
        // if(j==t.length()) return true;
        // if(i==s.length()) return false;

        // // match then take
        // if(s[i]==t[j]){
        //     return isSubsequence(s,t,i+1,j+1);
        // }
        int j = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s[j] == t[i])
                j++;
        }
        return (j == s.length());
    }
};