class Solution {
public:
    vector<string> readBinaryWatch(int setBit) {
        vector<string> ans;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == setBit) {
                    string st =
                        to_string(i) + ":"+ (j < 10 ? "0" : "") + to_string(j);
                    ans.push_back(st);
                }
            }
        }
        return ans;
    }
};