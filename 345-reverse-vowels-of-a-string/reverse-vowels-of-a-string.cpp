class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        set<char> ch = {'a','e','i','o','u','A','E','I','O','U'};
        while(i<j){
            while(i<j && ch.find(s[i]) == ch.end()) i++;
            while(i<j && ch.find(s[j]) == ch.end()) j--;
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};