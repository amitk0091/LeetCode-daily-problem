class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        vector<string> dp(strs.size(),"");
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<strs.size();j++){
                 dp[j] += strs[j][i];
            }


            int flag =0;
            for(int j=1;j<strs.size();j++){
                if(dp[j] < dp[j-1]){
                    flag=1;
                    break;
                }
            }

            if(flag){
                for(int j=0;j<strs.size();j++){
                    dp[j].pop_back();
                }
            }
        }
         return (strs[0].length() - dp[0].length());
    }
};