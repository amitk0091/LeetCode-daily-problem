class Solution {
public:
    string decodeString(string s) {
      string st,aux; 
      int len=0,n = s.length(),open=0;
      
      for(int i=0;i<n;i++){
        if(open>0){
            if(s[i]==']'){
                open--;
            }
            else if(s[i]=='[') open++;
            if(open==0){
              string new_str=decodeString(aux);
                while(len>0){
                    st+=new_str;
                    len--;
                }
                aux="";
                continue;
            }
            aux+=s[i];
        }
        else if(s[i]=='['){
            open++;
        }
        else{
            if(s[i]>='0' && s[i]<='9'){
                len*=10;
                len+=(s[i]-'0');
            }
            else{
                st+=s[i];
            }
        }
      }
    return st;
    }
};