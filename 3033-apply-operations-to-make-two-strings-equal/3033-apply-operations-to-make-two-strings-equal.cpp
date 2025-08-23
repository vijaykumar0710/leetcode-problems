class Solution {
public:
int t[501][501];
int f(int l,int r,int x,vector<int>&pos){
    if(l>r) return 0;
    if(r-l+1==2) return min(x,pos[r]-pos[l]);
    if(t[l][r]!=-1) return t[l][r];
    
    int ans=INT_MAX;
    for(int k=l+1;k<=r;k+=2){
        int pair_cost=min(x,pos[k]-pos[l]);
        ans=min(ans,f(l+1,k-1,x,pos)+pair_cost+f(k+1,r,x,pos));
    }
    return t[l][r]=ans;
}
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<int>mismatch_pos;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) mismatch_pos.push_back(i);
        }
        int m=mismatch_pos.size();
        if(m%2==1) return -1;
        memset(t,-1,sizeof(t));
        return f(0,m-1,x,mismatch_pos);
    }
};