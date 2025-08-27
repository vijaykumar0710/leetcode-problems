class Solution {
public:
int n;
int t[1001];
int f(int i,vector<int>&p){
    if(i>=n) return 0;
    if(t[i]!=-1) return t[i];
    int res=p[i];
    int limit=min(n,i+i+2);
    int mini=1e9;
    for(int j=i+1;j<=limit;j++){
        mini=min(mini,f(j,p));
    }
    res+=mini==1e9?0:mini;
    return t[i]=res;
}
    int minimumCoins(vector<int>& p) {
        n=p.size();
        memset(t,-1,sizeof(t));
        return f(0,p);
    }
};