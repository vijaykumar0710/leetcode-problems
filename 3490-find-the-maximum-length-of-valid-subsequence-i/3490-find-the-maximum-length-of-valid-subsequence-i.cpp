class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
       int odd_cnt=0,even_cnt=0,alternate_parity=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==0) even_cnt++;
            else if (nums[i]%2==1) odd_cnt++;
            if((nums[i]%2==0 && nums[i+1]%2==1) ||(nums[i]%2==1 && nums[i+1]%2==0)) alternate_parity++;
        }
        if(nums[n-1]%2==0) even_cnt++;
        if(nums[n-1]%2==1) odd_cnt++;
        return max({odd_cnt,even_cnt,alternate_parity+1});
    }
};