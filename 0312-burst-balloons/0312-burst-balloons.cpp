class Solution {
public:
int t[301][301];
int mcm(int i,int j,vector<int>&nums){
    if(i>j) return 0;
    int ans=INT_MIN;
    if(t[i][j]!=-1) return t[i][j];
    for(int k=i;k<=j;k++){
        int temp=(nums[i-1]*nums[k]*nums[j+1])
               + mcm(i,k-1,nums)+mcm(k+1,j,nums);
        ans=max(ans,temp);
    }
    return t[i][j]=ans;
}
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int i=1,j=nums.size()-2;
        memset(t,-1,sizeof(t));
        return mcm(i,j,nums);
    }
};