class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>t(101,0);
        for(int i=0;i<n;i++){
            t[nums[i]]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(t[nums[i]]!=0 && t[nums[i]]%k==0)sum+=nums[i];
        }
        return sum;
    }
};