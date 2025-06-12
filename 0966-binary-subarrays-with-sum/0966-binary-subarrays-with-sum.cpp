class Solution {
public:
int atmost(vector<int>&nums,int goal){
    int n=nums.size(),i=0,j=0,sum=0,subarray=0;
    while(j<n){
        sum+=nums[j];
        while(i<=j && sum>goal){
            sum-=nums[i];
            i++;
        }
        subarray+=j-i+1;
        j++;
    }
    return subarray;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};