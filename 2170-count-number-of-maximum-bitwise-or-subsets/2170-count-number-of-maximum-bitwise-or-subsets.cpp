class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxi_or=0;
        for(auto &x:nums) maxi_or|=x;
        int cnt=0;
        for(int mask=0;mask<(1<<n);mask++){
            int curr_or=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)) curr_or|=nums[i];
            }
            if(curr_or==maxi_or) cnt++;
        }
        return cnt;
    }
};