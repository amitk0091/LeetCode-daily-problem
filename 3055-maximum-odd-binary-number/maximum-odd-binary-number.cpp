class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string st;
        int cnt=0,n=s.length();
        for(int i=0;i<n;i++){
            cnt+= ( s[i]-'0');
        }
        int cntz = n-cnt;
        while(cnt>1){
            st+= '1';
            cnt--;
        }
        while(cntz--){
            st+='0';
        }
        st+= '1';
        return st;
    }
};