class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i+=3){
            if(arr[i+2]-arr[i]<=k) ans.push_back({arr[i],arr[i+1],arr[i+2]});
            else return {};
        }
        return ans;
    }
};