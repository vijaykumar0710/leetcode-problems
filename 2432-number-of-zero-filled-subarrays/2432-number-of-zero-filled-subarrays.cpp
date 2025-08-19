class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int i=0;
        while(i<n){
            int cnt=0;
            while(i<n && nums[i]==0){
                cnt++;
                i++;
            }
            ans+=(1LL*cnt*(cnt+1)/2);
            i++;
        }
        return ans;
    }
};