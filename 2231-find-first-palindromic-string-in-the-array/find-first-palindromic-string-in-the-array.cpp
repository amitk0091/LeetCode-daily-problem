class Solution {
public:
    bool checkPalin(string& st){
        int i=0,j=st.length()-1;
        while(i<j){
            if(st[i]!=st[j])return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto& word : words) if(checkPalin(word)) return word;
        return "";
    }
};