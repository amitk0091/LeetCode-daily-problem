class Solution {
public:
    int countSegments(string s) {
        int cnt=0;
        int c1=0;
        for(char ch : s){
            if(c1==0 && ch!=' '){ 
                cnt++;
                c1++;
            }
            else if (ch==' ') c1=0;
        }
        return cnt;
    }
};