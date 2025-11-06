class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size(),beauty=0;
        vector<int>prefix(n),suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++) prefix[i]=max(prefix[i-1],nums[i]);
        for(int i=n-2;i>=0;i--) suffix[i]=min(nums[i],suffix[i+1]);
        for(int i=1;i<n-1;i++){
            if(prefix[i-1]<nums[i] && nums[i]<suffix[i+1]) beauty+=2;
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]) beauty+=1;
        }
        return beauty;
    }
};