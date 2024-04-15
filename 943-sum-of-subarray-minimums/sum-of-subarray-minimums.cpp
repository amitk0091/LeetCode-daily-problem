using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<ll> st;
        ll sum =0,n=arr.size();
        for(ll i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                ll k = st.top();
                st.pop();
                ll left=-1;
                if(!st.empty()){
                    left = st.top();
                }
                left= (k-left-1);
                sum += (arr[k]*(left+1)*(i-k-1+1));
                sum%=MOD;
            }
            st.push(i);
        }
        while(!st.empty()){
           ll k = st.top();
                st.pop();
                ll left=-1;
                if(!st.empty()){
                    left = st.top();
                }
                left= (k-left-1);
                sum += (arr[k]*(left+1)*(n-k-1+1)); 
                sum%=MOD;
        }
        return sum%MOD;
    }
};