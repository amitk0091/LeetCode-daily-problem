class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        if(n==0) return 0;
        sort(tokens.begin(),tokens.end());
        int i=0,j =n-1,score=0;

        while( i <= j){
            if(power >= tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(score>0 && i<j) {
                power+=tokens[j];
                j--;
                score--;
            }
            else break;
        }
        return score;
    }
};