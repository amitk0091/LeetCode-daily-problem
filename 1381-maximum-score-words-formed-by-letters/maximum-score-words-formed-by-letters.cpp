class Solution {
public:
    bool check(string st,vector<int> freq){
        for(char ch : st){
            freq[ch-'a']--;
            if(freq[ch-'a']<0) return false;
        }
        return true;
    }
    int help(int i, vector<string>& w, vector<int>& freq, vector<int>& s){
        if(i==w.size()) return 0;
        int score=0;
        if(check(w[i],freq)){
           for(char ch : w[i]){
              freq[ch-'a']--;
              score+=s[ch-'a'];
           }
           score+= help(i+1,w,freq,s);
            for(char ch : w[i]){
              freq[ch-'a']++;
           }
        }
        score = max(score, help(i+1,w,freq,s));
        return score;
    }
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
      vector<int> freq(26);
      for(char ch : l) freq[ch-'a']++;
      return help(0,w,freq,s);
    }
};