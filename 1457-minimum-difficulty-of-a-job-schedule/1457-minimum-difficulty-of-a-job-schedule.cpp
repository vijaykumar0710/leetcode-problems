class Solution {
public:
int t[301][11];
int solve(int i,int j,vector<int>& jobDifficulty,int d){
    if(d==1) return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
    int res=INT_MAX;
    if(t[i][d]!=-1) return t[i][d];
    for(int k=i;k<=j-d;k++){
        int maxi=*max_element(jobDifficulty.begin()+i,jobDifficulty.begin()+k);
        maxi=max(maxi,jobDifficulty[k]);
        int temp=maxi+solve(k+1,j,jobDifficulty,d-1);
        res=min(res,temp);
    }
    return t[i][d]=res;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        int i=0,j=n;
        memset(t,-1,sizeof(t));
       return solve(i,j,jobDifficulty,d);
    }
};