class Solution {
public:
int t[101];
int f(int i,vector<int>&nums,int last_idx){
    if(i<last_idx) return 0;
    if(i==last_idx) return nums[i];
    if(t[i]!=-1) return t[i];
    int take=nums[i]+f(i-2,nums,last_idx);
    int skip=f(i-1,nums,last_idx);
    return t[i]=max(take,skip);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return *max_element(nums.begin(),nums.end());
        memset(t,-1,sizeof(t));
        int take_last_house=f(n-1,nums,1);
        memset(t,-1,sizeof(t));
        int take_sec_last_house=f(n-2,nums,0);
        return max(take_last_house,take_sec_last_house);
    }
};