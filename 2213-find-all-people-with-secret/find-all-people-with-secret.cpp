// class Solution {
// public:
//     static bool customComparator(vector<int>& a, vector<int>& b) {
//         if (a[2] < b[2])
//             return true;
//         return false;
//     }
//     int find_parent(int node, vector<int>& parent) {
//         if (parent[node] == node)
//             return node;
//         return parent[node] = find_parent(parent[node], parent);
//     }
//     vector<int> findAllPeople(int n, vector<vector<int>>& meets, int fp) {
//         int n1 = meets.size();
//         sort(meets.begin(), meets.end(), customComparator);
//         vector<int> parent(n, -1);
//         for (int i = 0; i < n; i++)
//             parent[i] = i;
//         parent[0] = 0;
//         parent[fp] = 0;

//         unordered_set<int> personKnowSecret;
//         personKnowSecret.insert(0);
//         personKnowSecret.insert(fp);
//         vector<int> stocks;
//         for (int i = 0; i < n1; i++) {
//             vector<int> meet = meets[i];
//             int p1 = find_parent(meet[0], parent);
//             int p2 = find_parent(meet[1], parent);
//             if (personKnowSecret.find(p1) != personKnowSecret.end()) {
//                 parent[meet[0]] = p1;
//                 parent[p2] = p1;
//                 personKnowSecret.insert(meet[1]);
//             } else if (personKnowSecret.find(p2) != personKnowSecret.end()) {
//                 parent[p1] = p2;
//                 parent[meet[1]] = p2;
//                 personKnowSecret.insert(meet[0]);
//             } else {
//                 parent[meet[1]] = meet[0];
//                 stocks.push_back(meet[0]);
//                 stocks.push_back(meet[1]);
//             }
//             if (i==n1 -1 || i + 1 < n1 && meets[i + 1][2] != meet[2]) {
//                 for(int stock :stocks){
//                     if(personKnowSecret.find(parent[stock]) != personKnowSecret.end()){
//                        personKnowSecret.insert(stock);
//                     }
//                     if(personKnowSecret.find(stock) != personKnowSecret.end()){
//                         personKnowSecret.insert(parent[stock]);
//                     }
//                     else parent[stock]= stock;
//                 }
//                 stocks.clear();
//             }
//         }
//         vector<int> ans(personKnowSecret.begin(), personKnowSecret.end());
//         return ans;
//     }
// };
// // map<int,set<int>> m;
// // for(int i=0;i<meet.size();i++){
// //     m[meet[i][2]].insert(meet[i][0]);
// //     m[meet[i][2]].insert(meet[i][1]);
// // }
// // unordered_set<int> personKnowSecret;
// // personKnowSecret.insert(0);
// // personKnowSecret.insert(fp);

// // for(auto& [time,personInMeet] : m){
// //     int viral = false;
// //     for(auto person : personKnowSecret){
// //         if(personInMeet.find(person)!=personInMeet.end()){  // jisko secret
// //         pta h woh meeting me h
// //             viral=true;
// //             break;
// //         }
// //     }
// //     if(viral){
// //         for(auto & person : personInMeet){
// //             personKnowSecret.insert(person);
// //         }
// //     }
// // }
// // vector<int> ans(personKnowSecret.begin(),personKnowSecret.end());
// // return ans;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        // Initialize parent and rank arrays
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // Find parent of node x. Use Path Compression
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        // Unite two nodes x and y, if they are not already united
        int px = find(x);
        int py = find(y);
        if (px != py) {
            // Union by Rank Heuristic
            if (rank[px] > rank[py]) {
                parent[py] = px;
            } else if (rank[px] < rank[py]) {
                parent[px] = py;
            } else {
                parent[py] = px;
                rank[px] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        // Check if two nodes x and y are connected or not
        return find(x) == find(y);
    }

    void reset(int x) {
        // Reset the initial properties of node x
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Sort meetings in increasing order of time
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        // Group Meetings in increasing order of time
        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].emplace_back(x, y);
        }
    
        // Create graph
        UnionFind graph(n);
        graph.unite(firstPerson, 0);

        // Process in increasing order of time
        for (auto& [t, meetings] : sameTimeMeetings) {
            // Unite two persons taking part in a meeting
            for (auto& [x, y] : meetings) {
                graph.unite(x, y);
            }
            
            // If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
            for (auto& [x, y] : meetings) {
                if (!graph.connected(x, 0)) {
                    // No need to check for y since x and y were united
                    graph.reset(x);
                    graph.reset(y);
                }
            }
        }
        
        // Al those who are connected to 0 will know the secret
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (graph.connected(i, 0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};