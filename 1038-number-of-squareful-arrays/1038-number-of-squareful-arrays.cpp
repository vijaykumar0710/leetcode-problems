class Solution {
public:
int n,cnt=0;
vector<int>used;
bool isSquare(int a){
    int x=sqrt(a);
    return x*x==a;
}
void f(vector<int>&nums,int depth,int prev){
    if(depth==n){
         cnt++;
         return;
         }
         for(int i=0;i<n;i++){
           if(used[i]) continue;
           if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
           if(prev==-1 || isSquare(nums[prev]+nums[i])){
            used[i]=1;
            f(nums,depth+1,i);
            used[i]=0;
           }
         }
}
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        used.assign(n,0);
        f(nums,0,-1);
        return cnt;
    }
};