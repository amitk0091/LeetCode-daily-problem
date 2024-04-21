using ll = long long;
class Solution {
public:
    int findNthDigit(int n) {
        ll digit =9,f=1,len=1;
        while(n>digit*len){
            n -= digit*len;
            len++;
            f *= 10; // first 1 10 100 1000
            digit *=10;   //9 90 900 9000
        }
        f+= (n-1)/len;
        string str = to_string(f);
        return str[(n-1)%len]-'0';
    }
};