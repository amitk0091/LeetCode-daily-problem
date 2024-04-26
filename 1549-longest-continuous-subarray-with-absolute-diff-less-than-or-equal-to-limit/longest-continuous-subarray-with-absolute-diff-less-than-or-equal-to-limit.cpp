class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        // map<int, int> m;
        // int mx = 0, mn = INT_MAX;
        deque<int> dqmx,dqmn;
        int j = 0,ans=1;
        for (int i = 0; i < n; i++) {
            while(!dqmx.empty() && dqmx.back() < nums[i]) dqmx.pop_back();
            while(!dqmn.empty() && dqmn.back() > nums[i]) dqmn.pop_back();
            
            dqmx.push_back(nums[i]);
            dqmn.push_back(nums[i]);

            // m[nums[i]]++;
             
           int mx = dqmx.front();
           int mn = dqmn.front();
           while(j<=i && mx-mn>limit){
              if(nums[j]==dqmx.front()) dqmx.pop_front();
              if(nums[j]==dqmn.front()) dqmn.pop_front();
              mx = dqmx.front();
              mn = dqmn.front();
              j++;
           }
            // int mn = min(nums[i], mn);
            // while (j<=i && mx - mn > limit) {
            //     m[nums[j]]--;
            //     if (m[nums[j]] == 0)
            //         m.erase(nums[j]);
            //     mn = m.begin()->first;
            //     mx = m.rbegin()->first;
            //     j++;
            // }
            ans = max(ans,(i-j+1));
        }
        return ans;
    }
};