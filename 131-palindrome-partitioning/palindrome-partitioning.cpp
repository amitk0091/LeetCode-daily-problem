class Solution {
public:
    vector<vector<string>> ans;
    bool check(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<string> aux;
    void help(int i,string& s){
        if(i==s.length()) {
            ans.push_back(aux);
            return ;
        }
        string st;
        for(int k=i;k<s.length();k++){
            st+=s[k];
            if(check(i,k,s)){
                aux.push_back(st);
                help(k+1,s);
                aux.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       help(0,s);
       return ans;
    }
};