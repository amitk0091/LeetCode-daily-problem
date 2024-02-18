class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n);
        int m = meetings.size();
        sort(meetings.begin(),meetings.end());

        priority_queue<int,vector<int>,greater<int>>avail;
        // rooms available

        for(int i =0;i<n;i++){
            avail.push(i);
        }

        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long ,int>>> inUse;
        // duration , room

        for(auto m : meetings){
            while(!inUse.empty() && inUse.top().first <= m[0]){
                avail.push(inUse.top().second);
                inUse.pop();
            }

            long long duration= m[1]-m[0];
            long long start ;
            if(avail.empty()){
                start = inUse.top().first;
            }else{
                start = m[0];
            }

            int room = avail.empty() ? inUse.top().second : avail.top();

            if(avail.empty()){
                inUse.pop();
            }else{
                avail.pop();
            }
            rooms[room]++;

            inUse.push({start + duration , room});
        }

        int maxi =0,ans=0;
        for(int i =0;i<n;i++){
            if(rooms[i]>maxi){
                maxi = rooms[i];
                ans = i;
            }
        }
        return ans;
    }
};