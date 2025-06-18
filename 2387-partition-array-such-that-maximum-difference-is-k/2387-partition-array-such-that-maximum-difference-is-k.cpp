class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int small=nums[0];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]-small>k){
                cnt++;
                small=nums[i];
            }
        }
        cnt++;
        return cnt;
    }
};