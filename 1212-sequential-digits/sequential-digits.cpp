class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9-i+1;j++){
                int digits=i;
                int val=0,start=j;
                while(digits--){
                    val*=10;
                    val+=start;
                    start++;
                }
                if(val>=low && val<=high) ans.push_back(val);
            }
        }
        return ans;
    }
};