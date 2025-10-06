class Solution {
public:
int n;
vector<int>prefix_sum(vector<int>&nums){
    vector<int>prefix(n);
    prefix[0]=0;
    for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i-1];
    return prefix;
}
vector<int>suffix_sum(vector<int>&nums){
    vector<int>suffix(n);
    suffix[n-1]=0;
    for(int i=n-2;i>=0;i--) suffix[i]=suffix[i+1]+nums[i+1];
    return suffix;
}
    int findMiddleIndex(vector<int>& nums) {
        n=nums.size();
        vector<int>prefix=prefix_sum(nums);
        vector<int>suffix=suffix_sum(nums);
        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]) return i;
        }
        return -1;
    }
};