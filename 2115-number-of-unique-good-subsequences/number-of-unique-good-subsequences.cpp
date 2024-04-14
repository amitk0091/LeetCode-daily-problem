using ll= long long;
const int MOD = 1e9 +7;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string bin) {
        ll zero=0,one=0;        
        for(char& ch : bin){
            if(ch=='0'){
               zero = (one+zero)%MOD;
            }
            else{
                one = (one + zero +1)%MOD;
            }
        }
        return (zero + one + (zero || bin[0]=='0'))%MOD;
    }
};