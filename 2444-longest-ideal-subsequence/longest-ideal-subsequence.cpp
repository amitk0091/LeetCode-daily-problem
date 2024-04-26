class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26]={0};
        int ans=0;
        for(int i=s.length()-1;i>=0;i--){
            int p = s[i]-'a';
            int len=0;
            for(int j=0;j<26;j++){
                 if(abs(p-j)<=k){
                    len=max(dp[j],len);
                 }
            }
            dp[p] = len+1;
            ans=max(ans,dp[p]);
        } 
        return ans;
    }
};