using ll = long long;
const int MOD = 1e9 + 7;


class Solution {
public:
    pair<int, int> get_smaller_And_Equal_or_larger(vector<int>& arr, int num) {
        int low = 0, high = arr.size() - 1, small = -1, large = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] < num) {
                small = arr[mid];
                low = mid + 1;
            } else {
                large = arr[mid];
                high = mid - 1;
            }
        }
        return {small, large};
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        vector<ll> vt(nums1.size());
        ll sum=0;
        for(int i=0;i<nums1.size();i++){
           sum+=abs(nums1[i]-nums2[i]);
           if(nums1[i]>=nums2[i]){
                vt[i] = nums1[i]-nums2[i];
           }
           else{
             vt[i] = nums2[i] -nums1[i];
           }
        }
        sort(nums1.begin(),nums1.end());
        ll res = sum;
        ll temp = sum;
        cout<<"sum "<<sum<<endl;
        for(int i=0;i<nums1.size();i++){
           temp-=vt[i];
           auto p = get_smaller_And_Equal_or_larger(nums1,nums2[i]);
           ll extra = INT_MAX;
           if(p.second!=-1){
            extra= (p.second-nums2[i]);
           }
           if(p.first!=-1) extra = min(extra,(ll)(nums2[i]-p.first));
           res= min(temp+extra,res);
           cout<<p.first<<" "<<p.second<<endl;
           cout<<"extra "<<extra<<endl;
           temp=sum;
        }
        return res%MOD;
    }
};