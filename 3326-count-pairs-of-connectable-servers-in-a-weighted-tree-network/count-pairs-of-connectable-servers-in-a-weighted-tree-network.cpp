class Solution {
public:
    vector<pair<int, int>> dfs(int node, int mod, vector<bool>& vis,
                               vector<int>& ans,
                               vector<pair<int, int>> adj[],
                               vector<int>& upper,
                               vector<int>& sumNodes) {
        // cout<<"start "<<node<<endl;
        vis[node] = true;

        vector<pair<int, int>> vt;
        for (auto k : adj[node]) {
            if (!vis[k.first]) {
                vector<pair<int, int>> dis =
                    dfs(k.first, mod, vis, ans, adj, upper,sumNodes);
                int cnt = 0;
                for (int i = 0; i < vt.size(); i++) {
                    for (int j = 0; j < dis.size(); j++) {

                        if ((vt[i].second + dis[j].second + k.second) % mod ==
                            0)
                            upper[vt[i].first]++, upper[dis[j].first]++;
                    }
                }
                for (int j = 0; j < dis.size(); j++) {

                    if ((dis[j].second + k.second) % mod == 0)
                        cnt++, upper[dis[j].first]++;
                    vt.push_back({dis[j].first, dis[j].second + k.second});
                }
                if(cnt>0) ans[node]+=sumNodes[node]*cnt,sumNodes[node]+=cnt;
            }
        }
      
        vt.push_back({node, 0});
        return vt;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                               int mod) {
        int n = edges.size() + 1;
        vector<int> ans(n);
        vector<int> upper(n);
        vector<int> sumNodes(n);
        vector<bool> vis(n, false);

        vector<pair<int, int>> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                root = i;
                break;
            }
        }
        
        dfs(root, mod, vis, ans, adj, upper,sumNodes);

        for (int i = 0; i < n; i++) {
            cout<<upper[i]<<" "<<ans[i]<<endl;
            if(upper[i]>0) ans[i]+= sumNodes[i]*upper[i];
        }
        return ans;
    }
};