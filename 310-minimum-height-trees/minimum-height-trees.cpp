class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n);
        vector<int> adj[n];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
            indeg[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 1 || adj[i].size() == 0) {
                q.push(i);
            }
        }
        int m = n;
        while (m > 2) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                cout<<node<<endl;
                m--;
                for (auto neigh : adj[node]) {
                    indeg[neigh]--;
                    if (indeg[neigh] == 1)
                       { 
                        cout<<neigh <<" pu "<<endl;
                        q.push(neigh);
                        }
                }
            }
        }
        if (q.size() == 1)
            return {q.front()};
        int a = q.front();
        q.pop();
        return {a,q.front()};
    }
};