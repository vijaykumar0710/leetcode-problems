class Solution {
public:
int t[301][11];
int solve(int i,vector<int>& jobDifficulty,int d,int n){
    if(d==1) return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
    int res=INT_MAX;
    if(t[i][d]!=-1) return t[i][d];
    int maxi=0;
    for(int k=i;k<=n-d;k++){
       // int maxi=*max_element(jobDifficulty.begin()+i,jobDifficulty.begin()+k+1);
        for(int j=i;j<=k;j++){
            maxi=max(maxi,jobDifficulty[j]);
        }
        int temp=maxi+solve(k+1,jobDifficulty,d-1,n);
        res=min(res,temp);
    }
    return t[i][d]=res;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        memset(t,-1,sizeof(t));
       return solve(0,jobDifficulty,d,n);
    }
};