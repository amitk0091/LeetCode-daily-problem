class Solution {
public:
    int timeRequiredToBuy(vector<int>& tk, int k) {
        int n= tk.size(),ans=0;
        for(int i=0;i<n;i++){
            if(i<=k) ans+=min(tk[k],tk[i]);
            else ans+=min(tk[k]-1,tk[i]);
        }
        return ans;
    }
};