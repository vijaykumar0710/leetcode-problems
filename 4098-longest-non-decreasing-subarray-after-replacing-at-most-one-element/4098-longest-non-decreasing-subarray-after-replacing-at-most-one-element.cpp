class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<int>L(n),R(n);
        L[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]) L[i]=L[i-1]+1;
            else L[i]=1;
        }
        R[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) R[i]=R[i+1]+1;
            else R[i]=1;
        }
        int res=0;
       for(int i=0;i<n;i++){
           int left=(i>0)?L[i-1]:0;
           int right=(i<n-1)?R[i+1]:0;
           if(i>0 && i<n-1 && nums[i-1]<=nums[i+1]){
               res=max(res,left+1+right);
           }else{
               res=max(res,left+1);
               res=max(res,right+1);
           }
       }
        return min(res,n);
    }
};