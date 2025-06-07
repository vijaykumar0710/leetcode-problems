class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>>t(n,vector<long long>(n,1e9));
       for(int i=0;i<n;i++) t[i][i]=0;
       for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        t[u][v]=w;
        t[v][u]=w;
       }
       for(int via=0;via<n;via++){
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                t[i][j]=min(t[i][j],t[i][via]+t[via][j]);
            }
          }
       }
       int res_idx=-1;
       int count=n;
       for(int i=0;i<n;i++){
        int tmp_cnt=0;
        for(int j=0;j<n;j++){
          if(t[i][j]<=distanceThreshold)
             tmp_cnt++;
          }
           if(tmp_cnt<=count){
            count=tmp_cnt;
            res_idx=i;
           }
       }
       return res_idx;
    }
};