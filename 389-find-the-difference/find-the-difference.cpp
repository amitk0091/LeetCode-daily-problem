class Solution {
public:
    char findTheDifference(string s, string t) {
        int sm=0;
        for(char ch : t) sm+=(ch-'a');
        for(char ch : s) sm-=(ch-'a');
        return 'a'+sm;
    }
};