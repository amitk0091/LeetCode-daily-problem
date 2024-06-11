class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // map<int,int> mp;
        // for(int i=0;i<arr1.size();i++){
        //     mp[arr1[i]]++;
        // }
        // int cnt=0;
        // for(int i=0;i<arr2.size();i++){
        //     while(mp[arr2[i]]>0){
        //         arr1[cnt++]=arr2[i];
        //         mp[arr2[i]]--;
        //     }
        // }
        // for(auto it : mp){
        //     int value = it.first;
        //     int c1 = it.second;
            
        //     while(c1--){
        //        arr1[cnt++] = value; 
        //     }
        // }
        // return arr1;

        int freq[1001]={0};
        for(int i=0;i<arr1.size();i++){
            freq[arr1[i]]++;
        }
        vector<int> res;
        for(int& e : arr2){
           while(freq[e]>0){
              res.push_back(e);
              freq[e]--;
           }
        }
        for(int i=0;i<=1000;i++){
            while(freq[i]>0){
                res.push_back(i);
               freq[i]--;
            }
        }
        return res;
    }
};