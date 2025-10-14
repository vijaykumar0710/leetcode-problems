class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        unordered_map<int,vector<int>>mp;
        for(auto e:edges){
            mp[e[0]].push_back(vals[e[1]]);
            mp[e[1]].push_back(vals[e[0]]);
        }
        vector<long long>t(n,INT_MIN);
        for(int i=0;i<n;i++){
            auto vec=mp[i];
            t[i]=vals[i];
            sort(vec.rbegin(),vec.rend());
            for(int j=0;j<k&&j<vec.size();j++){
                t[i]=max(t[i],t[i]+vec[j]);
            }
        }
        return *max_element(t.begin(),t.end());
    }
};