class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,res=0;
        if(nums[0]==1) cnt=1; 
        for(int i=1;i<n;i++){
           if(nums[i]==1) cnt++;
           else {
            res=max(res,cnt);
            cnt=0;
           }
        }
        res=max(res,cnt);
        return res;
    }
};