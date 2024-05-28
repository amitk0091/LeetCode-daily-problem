class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int curCost = 0, n = s.length(), j = 0, i = 0 , mxlen = 0, len=0;

        while (j < n) {
            curCost += abs(s[j] - t[j]);
            while(curCost>maxCost){
                curCost-=abs(s[i]-t[i]);
                i++;
            }
            
            if(i<=j) mxlen= max(mxlen, j-i+1);
            j++;
        }
        return mxlen;
    }
};

// int equalSubstring(string s, string t, int maxCost) {
//     int n = s.length();
//     vector<int> pre(n);
//     int cost =0;
//     int ans=0;
//     for(int i=0;i<n;i++){
//         cost += abs(s[i]-t[i]);
//         pre[i] = cost;
//         cout<<pre[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<n;i++){
//         int k = lower_bound(pre.begin(),pre.end(),pre[i]-maxCost) -
//         pre.begin(); if(pre[k] == pre[i] - maxCost || pre[i]<=maxCost){
//             ans = max(ans,i-k+1);
//         }
//         else{
//              ans = max(ans,i-k);
//         }

//         cout<<k<<endl;
//     }
//     return ans;
// }