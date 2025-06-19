class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
         vector<int>diff(n+1,0);
         int prefix_sum=0;
        for(int i=0;i<n;i++){
            prefix_sum+=diff[i];
            int val=nums[i]+prefix_sum;
            if(val==0) continue;
            if(val<0 || i+k>n) return false;
             prefix_sum-=val;
            diff[i]-=val;
            diff[i+k]+=val;
        }
        return true;
    }
};