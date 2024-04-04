class Solution {
public:
    int maxDepth(string s) {
        int ans=0,cnt=0;
        for(char& ch : s){
            if(ch=='('){
              cnt++;
            }
            else if(ch==')'){
                cnt--;
            }
            ans= max(ans,cnt);
        }
        return ans;
    }
};