class Solution {
public:
vector<int>parent,rank;
 int find(int i){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i]);
 }
 void Union(int x,int y){
    int par_x=find(x);
    int par_y=find(y);
    if(par_x==par_y) return;
    if(rank[par_x]>rank[par_y]) parent[par_y]=par_x;
    else if(rank[par_x]<rank[par_y]) parent[par_x]=par_y;
    else{
        parent[par_x]=par_y;
        rank[par_y]++;
    }
 }
 int isValid(int n,int mid,vector<vector<int>>& edges, int k){
    rank.resize(n,0);
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i]=i;
     for(auto &e:edges){
      int u=e[0],v=e[1],wt=e[2];
      if(wt<=mid) Union(u,v);
     }
     unordered_set<int>st;
     for(int i=0;i<n;i++){
        st.insert(find(i));
     }
     return st.size()<=k; 
 }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int l=0,r=1e6;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(n,mid,edges,k)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};