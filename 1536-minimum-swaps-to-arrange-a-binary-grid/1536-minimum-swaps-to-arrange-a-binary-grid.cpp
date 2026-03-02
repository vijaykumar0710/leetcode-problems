class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        // vector<int>zero(n,0);
        // int temp=n-1;
        // while(temp>0){
        //   zero[temp]=temp;
        //   temp--;
        // }
        // for(int j=1;j<n;j++){
        //     int cnt=0;
        //     for(int i=0;i<n;i++){
        //        if(grid[i][j]==0) cnt++;
        //     }
        //     if(cnt<zero[j]) return -1;
        // }
        vector<int>row_zero(n);
        for(int r=0;r<n;r++){
            int j=n-1,zero_cnt=0;
            while(j>=0){
                if(grid[r][j]!=0) break;
                else zero_cnt++,j--;
            }
            row_zero[r]=zero_cnt;
        }
        int steps=0;
        for(int i=0;i<n;i++){
            int zero_need=n-i-1;
            if(row_zero[i]>=zero_need) continue;
            bool flag=false;
            for(int j=i+1;j<n;j++){
                if(row_zero[j]>=zero_need){
                    flag=true;
                  for(int k=j;k>i;k--){
                   swap(row_zero[k],row_zero[k-1]);
                   steps++;
                  }
                  break;
                }
            }
            if(flag==false) return -1;
        }
        return steps;
    }
};