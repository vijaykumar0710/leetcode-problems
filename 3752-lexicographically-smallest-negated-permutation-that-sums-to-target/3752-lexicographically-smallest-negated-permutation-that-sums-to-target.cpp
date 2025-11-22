class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
      vector<int>nums;
        long long sum=0;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
            sum=(long long)sum+i;
        }
        long long t=sum-target;
        if(target<-sum || target>sum || t%2!=0) return {};
        for(int j=n-1;j>=0;j--){
            if(1ll*2*nums[j]<=t){
                t=t-1ll*2*nums[j];
                nums[j]=-1*nums[j];
            }
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};