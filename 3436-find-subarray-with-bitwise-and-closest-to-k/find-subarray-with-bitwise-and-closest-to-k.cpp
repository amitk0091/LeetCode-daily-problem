class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int arr[100001][31]={0};
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            int cnt=0;
            while(x>0){
                arr[i][cnt] = (i-1>=0 ? arr[i-1][cnt]:0) + (x&1);
                x= (x>>1);
                cnt++;
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int low = i, high = n-1;
            while(low<=high){
                int mid =(low+high)>>1;
                int num =0;
                for(int j=0;j<=30;j++){
                    int cnt = arr[mid][j] - (i ==0 ? 0 : arr[i-1][j]);
                    if(cnt == (mid-i+1)){
                        num += (1<<j);
                    }
                }
                ans = min(abs(num - k),ans);
                if(num>k){
                   low = mid+1;
                }
                else if(num==k) {
                    return 0;
                }
                else {
                    high= mid-1;
                }

            }
        }

       return ans;
    }
};