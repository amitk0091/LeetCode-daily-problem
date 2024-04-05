class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(),sum=0,totalCnt=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){

            sum+=((boxes[i]-'0')*i);
            totalCnt+=(boxes[i]-'0');
        }
        int cnt=0,left=0;
        for(int i=0;i<n;i++){
            int steps = (i*cnt-left);
            steps+=(sum-i*(boxes[i]-'0')-left - (totalCnt-cnt-(boxes[i]-'0'))*i);
            cnt+=(boxes[i]-'0');
            left+=((boxes[i]-'0')*i);
            ans[i]=steps;
        }
        return ans;
    }  
};