class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int total=accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        int i;
        for(i=0;i<n;i++){
            sum+=nums[i];
        int rem=total-sum;
        if(sum>rem) break;
        }
        cout<<i;
        vector<int>res;
        while(i>=0) res.push_back(nums[i]),i--;
        sort(res.rbegin(),res.rend());
        return res;
    }
};