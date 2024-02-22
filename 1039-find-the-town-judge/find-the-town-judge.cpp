class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> haveTrustedSomeone(n+1);
        vector<int> peopleTrust(n+1);
        for(int i=0;i<trust.size();i++){
            haveTrustedSomeone[trust[i][0]]++;
            peopleTrust[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(haveTrustedSomeone[i]==0 && peopleTrust[i] ==n-1 ){
                return i;
            }
        }
        return -1;
    }
};