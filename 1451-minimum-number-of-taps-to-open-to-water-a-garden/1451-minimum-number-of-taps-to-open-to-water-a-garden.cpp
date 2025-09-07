class Solution {
public:
map<pair<int,int>,int>mp;
int f(int i,int maxi,int n,vector<pair<int,int>>&pairs){
if(i>=pairs.size()){
    if(maxi>=n) return 0;
    return 1e9;
}
if(mp.find({i,maxi}) != mp.end())
      return mp[{i,maxi}];
if(pairs[i].first>maxi) return 1e9;
int skip=f(i+1,maxi,n,pairs);
int take=1+f(i+1,max(maxi,pairs[i].second),n,pairs);
return mp[{i,maxi}]=min(skip,take);
}
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>pairs;
        for(int i=0;i<=n;i++){
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            pairs.push_back({l,r});
        }
        sort(pairs.begin(),pairs.end());
        int ans=f(0,0,n,pairs);
        return ans==1e9?-1:ans;
    }
};