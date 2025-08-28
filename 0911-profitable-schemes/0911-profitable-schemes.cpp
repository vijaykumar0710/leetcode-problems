const int M=1e9+7;
class Solution {
public:
int sz;
int t[101][101][101];
int f(int i,int cnt,int sum,int n,int minProfit,vector<int>& group,vector<int>& profit){
if(i>=sz) return sum>=minProfit;
if(t[i][cnt][sum]!=-1) return t[i][cnt][sum];

long long res=0;

if(cnt+group[i]<=n){
int new_sum=sum+profit[i];
if(new_sum>=minProfit) new_sum=minProfit;
res+=f(i+1,cnt+group[i],new_sum,n,minProfit,group,profit);
}

res+=f(i+1,cnt,sum,n,minProfit,group,profit);

return t[i][cnt][sum]=res%M;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        sz=profit.size();
        memset(t,-1,sizeof(t));
        return f(0,0,0,n,minProfit,group,profit);
    }
};