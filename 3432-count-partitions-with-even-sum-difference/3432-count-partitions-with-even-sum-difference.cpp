class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix_sum(n,0);
        int total=nums[0];
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++){
            total+=nums[i];
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        int cnt=0;
        for(int j=0;j<n-1;j++){
            int a=total-prefix_sum[j];
            int b=prefix_sum[j];
             if(abs(a-b)%2==0){
                 cnt++;
             }
        }
        return cnt;
    }
};