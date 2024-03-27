class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long cnt =1,n = p.size(),ans=0;
        for(int i=1;i<n;i++){
             if(p[i]==p[i-1]-1) cnt++;
             else{ 
                ans+= (cnt*(cnt+1)/2);
                cnt=1;
            }
        }
        ans+=(cnt*(cnt+1)/2);
        return ans;
    }
};