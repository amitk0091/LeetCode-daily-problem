class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(52);
        for(char ch : s){
            if(ch>='A' && ch<='Z') freq[ch-'A'+26]++;
            else freq[ch-'a']++;
        }
        int single =0, dbl=0;
        for(int i=0;i<52;i++){
           dbl+= freq[i]/2;
           single+= freq[i]%2; 
        }
        return dbl*2+(single>0);
    }
};

// class Solution {
// public:
//     bool checkPalindrome(string s, int i, int j) {
//         while (i < j) {
//             if (s[i] != s[j])
//                 return false;
//         }
//         return true;
//     }
   
//     int longestPalindrome(string s) {
//         // n square
//         int n = s.length();
//         vector<vector<bool>> dp(n,vector<bool>(n,0));
//         for(int i=0;i<n;i++)dp[i][i] = true;
//         int i=1,ans=1;

//         while(i<n){
//             int j=0,k=i;
//             while(k<n && j<n){
//                 if(s[j] == s[k] && dp[j+1][k-1]){
//                   ans= max(ans,(k-i+1));
//                   dp[k][j] =true;
//                 }
//                 k++;
//                 j++;
//             }
//             i++;
//         }
//         return ans;
//     }
// };

