class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long op1=1ll*nums[0]*nums[1];
        long long op2=1ll*nums[n-1]*nums[n-2];
        long long op3=1ll*nums[0]*nums[n-1];
        if(op1<0){
            op1=1ll*op1*(-1e5);
        }else op1=1ll*op1*1e5;
        if(op2<0){
            op2=1ll*op2*(-1e5);
        }else op2=1ll*op2*1e5;
         if(op3<0){
            op3=1ll*op3*(-1e5);
        }else op3=1ll*op3*1e5;
        return max({op1,op2,op3});
    }
};