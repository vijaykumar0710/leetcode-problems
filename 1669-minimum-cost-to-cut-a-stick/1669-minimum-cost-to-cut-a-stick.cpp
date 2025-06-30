class Solution {
public:
int t[103][103];
int solve(int i,int j,vector<int>&cuts){
    if(j-i<=1) return 0;
    if(t[i][j]!=-1) return t[i][j];
    int res=INT_MAX;
    for(int k=i+1;k<j;k++){
        int cost=cuts[j]-cuts[i];
        int left=solve(i,k,cuts);
        int right=solve(k,j,cuts);
        res=min(res,(cost+left+right));
    }
  return t[i][j]=res;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(t,-1,sizeof(t));
        return solve(0,cuts.size()-1,cuts);
    }
};