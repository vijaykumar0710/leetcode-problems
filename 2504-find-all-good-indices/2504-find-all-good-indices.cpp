class Solution {
public:
int n;
vector<int>prefix_cal(vector<int>&nums){
    vector<int>prefix(n);
    prefix[0]=0,prefix[1]=1;
    for(int i=2;i<n;i++){
        if(nums[i-1]<=nums[i-2]) prefix[i]=1+prefix[i-1];
        else prefix[i]=1;
    }
    return prefix;
}
vector<int>suffix_cal(vector<int>&nums){
    vector<int>suffix(n);
    suffix[n-1]=0,suffix[n-2]=1;
    for(int i=n-3;i>=0;i--){
        if(nums[i+1]<=nums[i+2]) suffix[i]=1+suffix[i+1];
        else suffix[i]=1;
    }
    return suffix;
}
    vector<int> goodIndices(vector<int>& nums, int k) {
        n=nums.size();
        vector<int>res;
        vector<int>prefix=prefix_cal(nums);
        vector<int>suffix=suffix_cal(nums);
        for(int i=0;i<n;i++){
            if(prefix[i]>=k && suffix[i]>=k) res.push_back(i);
        }
        return res;
    }
};