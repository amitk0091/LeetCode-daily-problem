class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        bool flag= true;
        string ans;
        int i=0,j=0;
        while(i<word1.length() && j<word2.length()){
            if(flag){
                ans += word1[i];
                i++;
            }
            else{
                ans+=word2[j];
                j++;
            }
            flag^=1;
        }
        while(i<word1.length()){
            ans+= word1[i];
            i++;
        }
        while(j<word2.length()){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};