class Solution {
public:
    
    int subsetXORSum(vector<int>& nums) {
        long long sum =0;
        for(int i=1;i<(1<<nums.size());i++){
            int k =i, aux=0,cnt=nums.size()-1;
            
            while(k>0){
               if(aux==0 && k%2==1){
                 aux = nums[cnt];
               }
               else if(k%2==1){
                 aux ^= nums[cnt];
               }
               k/=2;
               cnt--;
            }
            sum+=aux;
        }
        return sum;
    }
};