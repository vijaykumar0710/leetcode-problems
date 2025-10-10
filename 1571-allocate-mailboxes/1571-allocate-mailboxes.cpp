class Solution {
public:
int dist[101][101];
int t[101][101];
int n;
int f(vector<int>&houses,int k,int start){
if(k==0 && start==n) return 0;
if(k==0 || start==n) return 1e7;
if(t[k][start]!=-1) return t[k][start];
int ans=1e7;
    for(int i=start;i<n;i++){
        ans=min(ans,dist[start][i]+f(houses,k-1,i+1));
    }
    return t[k][start]=ans;
}
    int minDistance(vector<int>& houses, int k) {
        n=houses.size();
        sort(houses.begin(),houses.end());
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int x=i;x<=j;x++){
                    dist[i][j]+=abs(houses[(i+j)/2]-houses[x]);
                }
            }
        }
        memset(t,-1,sizeof(t));
        return f(houses,k,0);
    }
};