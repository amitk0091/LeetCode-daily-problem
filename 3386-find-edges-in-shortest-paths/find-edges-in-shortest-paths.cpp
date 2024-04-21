using ll = long long;
typedef pair<int, int> pii; // pair for {distance, node}

class Solution {
public:
    vector<ll> dijkstra(int source, int n, vector<vector<pii>>& adj) {
        vector<ll> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq; // min-priority queue

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

   

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n); // adjacency list

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> vis(n, false);
        vector<ll> d1 = dijkstra(0, n, adj);
        vector<ll> d2 = dijkstra(n-1,n,adj);
        int cost = d1[n - 1];
        vector<bool> ans(edges.size(), false);
        if(cost == INT_MAX) return ans;
        for (int i = 0; i < edges.size(); i++) {
            if((d1[edges[i][0]] + d2[edges[i][1]] + edges[i][2] ==d1[n-1]) || (d1[edges[i][1]] + d2[edges[i][0]] + edges[i][2] ==d1[n-1])  ){
                ans[i] = true;
            }
        }

        return ans;
    }
};