class Solution {
public:
    bool dfs(int node, int dest, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;
        bool canReach = false;
        for(auto neigh:adj[node]){
            if(neigh==dest) return true;
            if(!vis[neigh]){
                canReach |= dfs(neigh,dest,adj,vis);
            }
        }
        return canReach;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        if(src==dest) return true;
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        return dfs(src, dest, adj,vis);
    }
};