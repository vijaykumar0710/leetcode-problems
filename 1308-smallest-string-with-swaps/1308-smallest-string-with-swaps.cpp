class Solution {
public:
vector<int>parent,rank;
int find(int i){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i]);
}
void Union(int x,int y){
    int p_y=find(y);
    int p_x=find(x);
    if(p_y==p_x) return;
    if(rank[p_y]>rank[p_x]) parent[p_x]=p_y;
    else if(rank[p_y]>rank[p_x]) parent[p_x]=p_y;
    else{
        parent[p_x]=p_y;
        rank[p_y]++;
    }
}
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto &pair:pairs){
            Union(pair[0],pair[1]);
        }
        unordered_map<int,vector<int>>groups;
        for(int i=0;i<n;i++){
            int root=find(i);
           groups[root].push_back(i);
        }
        string res=s;
        for(auto &[root,indices]:groups){
            string temp="";
            for(auto &idx:indices) temp+=s[idx];
            sort(indices.begin(),indices.end());
            sort(temp.begin(),temp.end());
            for(int i=0;i<indices.size();i++){
                res[indices[i]]=temp[i];
            }
        }
        return res;
    }
};