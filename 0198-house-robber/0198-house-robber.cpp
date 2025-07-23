class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return *max_element(nums.begin(),nums.end());
       int a=0,b=nums[0],c;
        for(int i=2;i<=n;i++){
            c=max(nums[i-1]+a,b);
            a=b;
            b=c;
        }
        return c;
    }
};