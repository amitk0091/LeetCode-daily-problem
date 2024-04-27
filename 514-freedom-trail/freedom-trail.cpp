class Solution {
public:
    // int dp[101][101];
    // int help(int i, int pre_j, string ring, string key) {
    //     if (i == key.length())
    //         return 0;
    //     if (dp[i][pre_j] != -1)
    //         return dp[i][pre_j];
    //     int cost = INT_MAX;
    //     for (int j = 0; j < ring.length(); j++) {
    //         if (ring[j] == key[i]) {
    //             int curCost = min(
    //                 (int)abs(j - pre_j) + 1,
    //                 (int)(ring.length() - max(j, pre_j) + min(pre_j, j) +
    //                 1));
    //             cost = min(cost, curCost + help(i + 1, j, ring, key));
    //         }
    //     }
    //     return dp[i][pre_j] = cost;
    // }
    int findRotateSteps(string ring, string key) {
        // fill_n(&dp[0][0],101*101,-1);
        // return help(0,0, ring, key);
        int dp[101][101] = {0};
        vector<int> prev(ring.length(), 0);
        vector<int> curr(ring.length(), 0);
        for (int i = key.length() - 1; i >= 0; i--) {
            fill(curr.begin(), curr.end(), INT_MAX);
            for (int pre_j = 0; pre_j < ring.length(); pre_j++) {
                int cost = INT_MAX;
                for (int j = 0; j < ring.length(); j++) {
                    if (ring[j] == key[i]) {
                        int curCost = min((int)abs(j - pre_j) + 1,
                                          (int)(ring.length() - max(j, pre_j) +
                                                min(pre_j, j) + 1));
                        cost = min(cost, curCost + prev[j]);
                    }
                }
                curr[pre_j] = cost;
            }
            prev = curr;
        }
        return prev[0];
    }
};