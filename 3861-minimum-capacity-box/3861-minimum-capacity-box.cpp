class Solution {
public:
    int minimumIndex(vector<int>& c, int it) {
        int n=c.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++) p.push_back({c[i],i});
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++) if(p[i].first>=it) return p[i].second;
        return -1;
    }
};