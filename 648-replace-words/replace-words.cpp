class Solution {
public:
    string replaceWords(vector<string>& dic, string s) {
        unordered_set<string> st(dic.begin(),dic.end());
        string matched="", curr="",ans;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ') curr+=s[i];
            if(st.find(curr)!=st.end() && matched.length()==0) matched=curr; 
            if(s[i]==' ' || i==s.length()-1){
               ans+=(matched.length()>0 ? matched :curr);
               curr="";
               matched="";
               if(i!=s.length()-1) ans+=' ';
            }
        }
        return ans;
    }
};