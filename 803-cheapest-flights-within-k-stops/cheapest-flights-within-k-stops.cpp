class Solution {
public:
    // vector<int> bellmanFord(int limit, int n, vector<vector<int>>& edge_weight,
    //                         int src) {
    //     vector<int> dis(n, INT_MAX);
    //     dis[src] = 0;
    //     int traverse = n - 1;
    //     while (traverse-- && limit--) {
    //         int flag = 1;
    //         for (int i = 0; i < edge_weight.size(); i++) {
    //             if (dis[edge_weight[i][0]] != INT_MAX &&
    //                 dis[edge_weight[i][0]] + edge_weight[i][2] <
    //                     dis[edge_weight[i][1]]) {
    //                 dis[edge_weight[i][1]] =
    //                     dis[edge_weight[i][0]] + edge_weight[i][2];
    //                 flag = 0;
    //             }
    //         }
    //         for (int i = 0; i < dis.size(); i++) {
    //             cout << dis[i] << " ";
    //         }
    //         cout << endl;
    //         if (flag)
    //             break;
    //     }
    //     return dis;
    // }
    vector<int> modifiedDijkstra(int limit, int n,
                                 vector<vector<int>>& edge_weight, int src) {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        vector<pair<int, int>> adj[n];
        for (auto& edge : edge_weight) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        queue<vector<int>> q1;
        q1.push({0, src, 0});
        while (!q1.empty()) {
            int stopused = q1.front()[0];
            int node = q1.front()[1];
            int dist = q1.front()[2];

            q1.pop();
            for (auto p : adj[node]) {
                if (dis[p.first] > dist + p.second) {
                    dis[p.first] = dist + p.second;
                    if (stopused + 1 < limit) {
                        q1.push({stopused + 1, p.first, dis[p.first]});
                    }
                }
            }
        }
        return dis;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src,
                          int dist, int k) {
        vector<int> dis = modifiedDijkstra(k+1, n, flights, src);
        return (dis[dist] == INT_MAX ? -1 : dis[dist]);
    }
};