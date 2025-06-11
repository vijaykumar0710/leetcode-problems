class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m=students.size(),n=students[0].size();
        vector<vector<int>>score(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(students[i][k]==mentors[j][k])
                      score[i][j]++;
                }
            }
        }

        int N=1<<m;
       //dp[mask]=maximum score using first 'k' students and assigned mentors in 'mask'
      vector<int>dp(N,0);
     
     for(int mask=0;mask<N;mask++){
        int studentIdx=__builtin_popcount(mask);
        for(int j=0;j<m;j++){
            if(!(mask&(1<<j))){
                int newMask=mask|(1<<j);
                dp[newMask]=max(dp[newMask],dp[mask]+score[studentIdx][j]);
            }
        }
     }
     return dp[N-1];
    }
};