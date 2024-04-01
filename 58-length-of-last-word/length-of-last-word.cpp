class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0,auxLen=0;
        for(char ch : s){
            if(ch==' ' && auxLen!=0){
                len=auxLen;
               auxLen=0;
            }
            else if(ch!=' '){
                auxLen++;
            }
        }
        if(auxLen!=0)len = auxLen;
        return len;
    }
};