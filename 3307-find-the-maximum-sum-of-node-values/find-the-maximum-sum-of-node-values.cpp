using ll = long long;
class Solution {
public:
    //     pair<ll,ll> dfs(int node,int parent,int k,vector<int>& nums,
    //     vector<ll> adj[]){
    //         ll sumXor= nums[node] ^ k;
    //         ll sum = nums[node];
    //         for(auto& k: adj[node]){
    //             if(k!=parent){
    //                pair<ll,ll> p = dfs(k,node,k,nums,adj);  // first XOR //
    //                second NOt xor sumXor+= p.first; sum +=p.second;
    //             }
    //         }

    //         return {sumXor,sum};
    //     }
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        int n = nums.size();
        ll diff = INT_MAX, cnt = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] ^ k) > nums[i]) {
                cnt++;
                
                sum += (nums[i] ^ k);
            } else
                sum += (nums[i]);
            if (abs((nums[i] ^ k) - nums[i]) < diff)
                    diff = abs((nums[i] ^ k) - nums[i]);
        }
        if (cnt % 2 != 0)
            sum -= diff;
        return sum;
    }
};

// int n = nums.size();
// vector<ll> adj[n];
// for(auto& edge : edges){
//     adj[edge[0]].push_back(edge[1]);
//     adj[edge[1]].push_back(edge[1]);
// }
// int root=-1;
// for(int i=0;i<n;i++){
//     if(adj[i].size()==1) {
//         root = i;
//         break;
//     }
// }
// pair<ll,ll> p = dfs(root,-1,k,nums,adj);
// return max(p.first,p.second);