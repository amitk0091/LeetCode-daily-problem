using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> arr(n,vector<int>(3,0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            arr[i][1] = nums[i];
            arr[i][2] = nums[i] ^ k;
            if (arr[i][1] < arr[i][2])
                cnt++;
            arr[i][0] = arr[i][2] - arr[i][1];
            cout<<arr[i][0]<<" ";
        }
        cout<<endl;
        sort(arr.begin(), arr.end());
        ll ans = 0;
        if (cnt % 2 == 0) {
            for (int i = 0; i < n; i++) {
                ans+=max(arr[i][1],arr[i][2]);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (i > 0 && arr[i][0] > 0 && arr[i - 1][0] < 0) {
                    if (abs(arr[i][0]) > abs(arr[i - 1][0])) {
                        ans += arr[i-1][0];
                        ans += arr[i][2];
                    } else
                        ans += arr[i][1];
                }
                else if(i==0 && arr[i][0]>0){
                    ans+=arr[i][1];
                }
                else{
                    ans+=max(arr[i][1],arr[i][2]);
                }
            }
        }
        return ans;
    }
};