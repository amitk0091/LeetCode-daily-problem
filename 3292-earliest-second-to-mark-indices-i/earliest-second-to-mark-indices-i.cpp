using ll = long long;
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        ll sum = accumulate(nums.begin(),nums.end(),0ll);
        unordered_set<int> st(changeIndices.begin(),changeIndices.end());        
        unordered_set<int> st2;

        if(sum + st.size() > changeIndices.size()) return -1;
        
        for(int i=0;i<changeIndices.size();i++){
            st2.insert(changeIndices[i]);
            sum--;
            // cout<<sum<<" sum "<<endl;
            if(sum<=0 && st2.size() ==nums.size()){
                // cout<<"for "<<i<<endl;
                unordered_set<int> st3;
                int p=i;
                for(int j=i;j>=0;j--){
                    // cout<<j<<" inside "<<p<<endl;
                    if(st3.find(changeIndices[j]) == st3.end()){
                        // cout<<"in"<<endl;
                        if(p>j) p=j;
                        p -= nums[changeIndices[j]-1]+1;
                        st3.insert(changeIndices[j]);
                    }
                }
                if(p>=-1) return i+1;
            }
        }
        return -1;
    }
};