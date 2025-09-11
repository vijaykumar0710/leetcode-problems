class Solution {
public:
int M=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>t(m,vector<int>(n));
        vector<int>vec(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=i*n+j;
                vec[idx]=grid[i][j];
            }
        }
        vector<long long>prefix(m*n),suffix(m*n);
        int sz=vec.size();
        prefix[0]=1,suffix[sz-1]=1;
        for(int i=1;i<sz;i++){
          prefix[i]=(1LL*prefix[i-1]%M*vec[i-1]%M);
          suffix[sz-i-1]=(1LL*suffix[sz-i]%M*vec[sz-i]%M);
        }
        for(int k=0;k<sz;k++){
            int i=k/n,j=k%n;
            t[i][j]=(1LL*prefix[k]%M*suffix[k]%M)%M;
        }
        return t;
    }
};