class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        long long nextPos=0,nextNeg=0;
        for(int i=n-1;i>=0;i--){
           long long curr1=nums[i]+max(nextPos,nextNeg);
           long long curr2=-nums[i]+nextPos;
           nextPos=curr1;
           nextNeg=curr2;
        }
        return nextPos;
    }
};