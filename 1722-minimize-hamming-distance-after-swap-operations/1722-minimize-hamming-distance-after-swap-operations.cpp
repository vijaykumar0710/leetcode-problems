class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x){
if(x==parent[x]) return x;
return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int x_par=find(x);
    int y_par=find(y);
    if(x_par==y_par) return;
    if(rank[x_par]>rank[y_par]){
        parent[y_par]=x_par;
    }else if(rank[y_par]>rank[x_par]){
        parent[x_par]=y_par;
    }else{
        parent[x_par]=y_par;
        rank[y_par]++;
    }
}
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,1);
        for(auto swap:allowedSwaps){
            Union(swap[0],swap[1]);
        }
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i=0;i<n;i++){
            int root=find(i);
            mp[root][source[i]]++;
        }
        int dist=0;
        for(int i=0;i<n;i++){
            int root=find(i);
           if(mp[root][target[i]]>0){
            mp[root][target[i]]--;
           }else{
              dist++;
           }
        }
        return dist;
    }
};