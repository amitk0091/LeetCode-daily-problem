class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < arr.size(); i++) {
            pq.push({-1.0 * arr[i] / arr[n - 1], {i, n - 1}});
        }
        while (--k) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            pq.push({-1.0 * arr[cur.first] / arr[cur.second - 1],
                     {cur.first, cur.second - 1}});
        }
        pair<int, int> ind = pq.top().second;
        return {arr[ind.first], arr[ind.second]};
    }
};