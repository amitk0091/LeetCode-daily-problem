class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
         int n = bl.size();
            long long ans=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int x1 = max(bl[i][0],bl[j][0]);
                    int y1 = max(bl[i][1],bl[j][1]);
                    int x2 = min(tr[i][0],tr[j][0]);
                    int y2 = min(tr[i][1],tr[j][1]);
                    // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
                    if(x2>=x1 && y2>=y1) {
                        long long k= min(x2-x1,abs(y2-y1));
                        ans= max(ans,k*k);
                    }
                    // cout<<ans<<endl;
                }
            }
        return ans;
    }
};