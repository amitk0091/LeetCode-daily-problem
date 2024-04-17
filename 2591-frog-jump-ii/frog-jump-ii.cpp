class Solution {
public:
    int maxJump(vector<int>& st) {
        int ans =0, n= st.size();
        ans = st[1]-st[0];
        for(int i=2;i<n;i+=2) ans= max(st[i]-st[i-2],ans);
        for(int i=3;i<n;i+=2) ans= max(st[i]-st[i-2],ans);
        return ans;
    }
};