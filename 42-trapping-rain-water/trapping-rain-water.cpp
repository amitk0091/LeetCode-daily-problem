class Solution {
public:
    int trap(vector<int>& h) {
        int ans=0;
        int mxl=0;
        int mxr=0;
        int i=0,j= h.size()-1;
        while(i<=j){
            mxl = max(h[i],mxl);
            mxr = max(h[j],mxr);
            if(mxl<=mxr){
                ans+= mxl-h[i];
                i++;
            }
            else{
               ans+=mxr-h[j];
               j--;
            }
        }
        return ans;
    }
};