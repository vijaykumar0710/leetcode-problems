class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        for(int i=0;i<n;i++){
        if(nums[i]==1) cnt1++; 
         }
         if(cnt1>0) return n-cnt1;
         int res=INT_MAX;
         for(int i=0;i<n-1;i++){
            int num=nums[i];
            for(int j=i+1;j<n;j++){
                num=gcd(num,nums[j]);
                if(num==1)res=min(res,j-i);
            }
         }
         return res==INT_MAX?-1:res+n-1;
    }
};