class Solution {
public:
bool isValid(int i,int j,vector<int>&nums){
 if(j>=nums.size()) return false;
 for(int it=i+1;it<=j;it++){
    if(nums[it]<=nums[it-1]) return false;
 }
 return true;
}
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return true;
        for(int i=0;i<=n-k;i++){
            if(isValid(i,i+k-1,nums)&&isValid(i+k,i+2*k-1,nums)) return true;
        }
        return false;
    }
};