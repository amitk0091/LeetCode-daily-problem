const string HEX = "0123456789abcdef";
class Solution {
public:
    
    string toHex(int num) {
        if(num==0) return "0";
        string ans;
        int cnt=0;
        while(num && cnt++ < 8){
            ans += HEX[(num & 0xf)] ;
            num>>=4;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};