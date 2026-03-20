class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
     int m=grid.size();
     int n=grid[0].size();
     vector<vector<int>>ans(m - k + 1,vector<int>(n - k + 1,0));
     if(k==1) return ans;
     for(int i=0;i<=m-k;i++){
        for(int j=0;j<=n-k;j++){
        vector<int>vec;
        unordered_set<int>st;
            for(int p=i;p<i+k;p++){
                for(int q=j;q<j+k;q++){
                  if(!st.count(grid[p][q])) vec.push_back(grid[p][q]);
                  st.insert(grid[p][q]);
                }
            }
            sort(vec.begin(),vec.end());
            if((int)st.size()==1) return ans;
            int diff=INT_MAX;
            for(int it=0;it<vec.size()-1;it++){
                diff=min(diff,abs(vec[it]-vec[it+1]));
            }
            ans[i][j]=diff;
        }
     }   
     return ans;
    }
};