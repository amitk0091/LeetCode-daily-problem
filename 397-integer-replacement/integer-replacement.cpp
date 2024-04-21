using ll = long long;
class Solution {
public:
    unordered_map<ll,ll> m;
    ll help(ll n){
        if(n==1) return 0;
        if(m.find(n)!=m.end()) return m[n];
        if(n%2==0) return 1+help(n/2);
        return m[n] = 1+min(help(n+1),help(n-1));
    }
    int integerReplacement(int n) {
        return help(n);
    }
};