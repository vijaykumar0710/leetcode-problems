class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1) return {1};
        vector<int>odd=beautifulArray((n+1)/2);
        vector<int>even=beautifulArray(n/2);
        vector<int>res;
        for(auto &x:odd) res.push_back(2*x-1);
        for(auto &x:even) res.push_back(2*x);
        return res;
    }
};