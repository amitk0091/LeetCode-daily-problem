class Solution {
public:
    // vector<vector<int>> MergeIntervals(vector<vector<int>>& meetings) {
    //     sort(meetings.begin(), meetings.end());
    //     vector<vector<int>> merged;
    //     int start = meetings[0][0], end = meetings[0][1];
    //     for (int i = 1; i < meetings.size(); i++) {
    //         if (meetings[i][0] > end) {
    //             merged.push_back({start, end});
    //             start = meetings[i][0];
    //         }
    //         end = max(end, meetings[i][1]);
    //     }
    //     merged.push_back({start, end});
    //     return merged;
    // }
    int countDays(int days, vector<vector<int>>& meetings) {
        // vector<vector<int>> mi = MergeIntervals(meetings);
        sort(meetings.begin(), meetings.end());
        int start = meetings[0][0], end = meetings[0][1];
        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] > end) {
                days -= (end-start+1);
                start = meetings[i][0];
            }
            end = max(end, meetings[i][1]);
        }
        days -= (end-start+1);
        // for (int i = 0; i < mi.size(); i++) {
        //     days -= (mi[i][1] - mi[i][0] + 1);
        // }
        return days;
    }
};