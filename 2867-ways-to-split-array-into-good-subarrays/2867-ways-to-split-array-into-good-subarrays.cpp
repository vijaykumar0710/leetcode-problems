class Solution {
public:
const int M=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        int zeros=0;
        long long ans=1;
        int i=0;
        while(i<n && nums[i]==0) i++;
            i++;
            if(i>n) return 0;
            int j=n-1;
            while(j>=0 && nums[j]==0)j--;
        while(i<=j){ 
           while(i<=j && nums[i]==0){
            zeros++;
            i++;
        }
         ans=(1LL*ans*(zeros+1))%M;
         zeros=0;
         i++;
        }
        return ans;
    }
};