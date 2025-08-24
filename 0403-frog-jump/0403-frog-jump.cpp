class Solution {
public:
int n;
unordered_map<int,int>mp;
map<pair<int,int>,bool>t;
bool f(int i,int k,vector<int>&stones){
    if(k<=0 || i>=n) return false;
    if(i==n-1) return true;
    if(t.count({i,k})) return t[{i,k}];
    bool flag=false;
    if(mp.count(stones[i]+k))flag|=f(mp[stones[i]+k],k,stones);
    if(mp.count(stones[i]+k-1))flag|=f(mp[stones[i]+k-1],k-1,stones); 
    if(mp.count(stones[i]+k+1))flag|=f(mp[stones[i]+k+1],k+1,stones);
    return t[{i,k}]=flag;
}
    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(stones[1]!=1) return false;
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        return f(1,1,stones);
    }
};