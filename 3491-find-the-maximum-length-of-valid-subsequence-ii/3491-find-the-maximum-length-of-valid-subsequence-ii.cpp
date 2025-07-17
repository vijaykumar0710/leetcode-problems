class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>t(n,vector<int>(k,0));
        int rem=(nums[1]+nums[0])%k;
        t[1][rem]=2;
        int res=2;
        for(int i=2;i<n;i++){
            for(int j=0;j<i;j++){
                 int rem=(nums[j]+nums[i])%k;
                 if(t[j][rem]!=0){ 
                 t[i][rem]=max(t[i][rem],t[j][rem]+1);
                 res=max(res,t[i][rem]);
                 }else t[i][rem]=2;
            }
        }
        return res;
    }
};