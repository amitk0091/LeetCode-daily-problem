class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        int freq[26]={0};
        for(char& ch: s){
            freq[ch-'a']++;
        }
        for(char& ch: order){
            int k = ch-'a';
            while(freq[k]>0){
                ans+=('a'+k);
                freq[k]--;
            }
        }
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                ans+=('a'+i);
                freq[i]--;
            }
        }
        return ans;
    }
};