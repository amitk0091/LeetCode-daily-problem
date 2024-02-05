class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        int freq[26];
        for(int i=0;i<s.length();i++) {
            char ch = s[i];
            if(freq[ch-'a']==0) freq[ch-'a']=i+1;
            else freq[ch-'a']=-1;
        }
        int ind = INT_MAX;
        for(int i=0;i<26;i++){
           if(freq[i]>0) ind=min(ind,freq[i]);
        }
        return (ind==INT_MAX ? -1:ind-1);
    }
};