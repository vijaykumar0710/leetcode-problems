class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
            for(int j=1;j<=n-2;j++){
                for(int k=j+1;k<n;k++){
                    res=min(res,nums[0]+nums[j]+nums[k]);
                }
            }
        return res;
    }
};