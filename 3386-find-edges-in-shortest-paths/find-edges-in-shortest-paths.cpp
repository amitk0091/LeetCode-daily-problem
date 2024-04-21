using ll = long long;
typedef pair<long, long> pii; // pair for {distance, node}

class Solution {
public:
    vector<ll>
    dijkstra(ll src, ll n,
             vector<vector<pii>>& adj) { // single source shortest path
        vector<ll> distance(n, INT_MAX);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            pq;
        pq.push({0, src});
        distance[src] = 0;

        while (!pq.empty()) {
            ll node = pq.top().second;
            pq.pop();
            for (auto p1 : adj[node]) {
                ll neigh = p1.first;
                ll nxtDis = p1.second;
                if (distance[neigh] > distance[node] + nxtDis) {
                    distance[neigh] = distance[node] + nxtDis;
                    pq.push({nxtDis + distance[node], neigh});
                }
            }
        }
        return distance;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n); // adjacency list

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> vis(n, false);
        vector<ll> d1 = dijkstra(0LL, (ll)n, adj);
        vector<ll> d2 = dijkstra((ll)(n - 1), (ll)n, adj);
        int cost = d1[n - 1];
        vector<bool> ans(edges.size(), false);
        if (cost == INT_MAX)
            return ans;
        for (int i = 0; i < edges.size(); i++) {
            if ((d1[edges[i][0]] + d2[edges[i][1]] + edges[i][2] ==
                 d1[n - 1]) ||
                (d1[edges[i][1]] + d2[edges[i][0]] + edges[i][2] ==
                 d1[n - 1])) {
                ans[i] = true;
            }
        }

        return ans;
    }
};