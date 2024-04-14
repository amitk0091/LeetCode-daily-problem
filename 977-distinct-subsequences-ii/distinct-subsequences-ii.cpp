
const int MOD = 1e9 + 7;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<long long> arr(26, 0);
        vector<long long> m(26, 0);
        long long prev = 0;
        for (char ch : s) {
            long long temp = prev;
            long long cnt = (prev * 2) % MOD + 1LL - 
                            (m[ch-'a'] ? (arr[ch - 'a'] + 1LL) : 0LL);
            cnt %= MOD;
            prev = cnt;
            cout << cnt << " cnt " << endl;
            arr[ch - 'a'] = temp;
            m[ch-'a']++;
        }
        if (prev < 0)
            prev += MOD;
        return prev;
    }
};

// class Solution {
// public:
//     int distinctSubseqII(string s) {
//         const int N = s.length();
//         const int MOD = 1e9 + 7;
        
//         vector<int> dp(N+1);
//         dp[0] = 1;
//         vector<int> last(26, -1);
        
//         for(int i = 0; i < N; i++){
//             int x = s[i] - 'a';
//             dp[i+1] = dp[i] * 2 % MOD;
//             if(last[x] >= 0) // if this is the first occurence of ch
//                 dp[i+1] -= dp[last[x]];
//             dp[i+1] %= MOD;
//             last[x] = i;
//             cout<<dp[i]<<endl;
//             }
//         dp[N]--;
//         if(dp[N] < 0) dp[N] += MOD;
//         return dp[N];
//     }
// };