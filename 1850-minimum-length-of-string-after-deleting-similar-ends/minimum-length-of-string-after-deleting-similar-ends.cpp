class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i=0,j=n-1;
       while(i<j && s[i]==s[j]){
            char ch =  s[i];
            while(i<j && s[i]==ch)i++;
            while(i<=j && s[j]==ch) j--;
       } 
    //    cout<<j<<" "<<i<<endl;
       return (j>=i ?  (j-i+1):0);
    }
};