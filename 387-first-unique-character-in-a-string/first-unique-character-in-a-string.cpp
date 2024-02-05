class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26];
        for(int i=0;i<s.length();i++) {
            if(freq[s[i]-'a']==0) freq[s[i]-'a']=i+1;
            else freq[s[i]-'a']=-1;
        }
        int ind = INT_MAX;
        for(int i=0;i<26;i++){
           if(freq[i]>0) ind=min(ind,freq[i]);
        }
        return (ind==INT_MAX ? -1:ind-1);
    }
};