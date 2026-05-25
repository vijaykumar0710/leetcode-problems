class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int freq=1;
        while(i<n-1){
            if(freq>=k){
                while(i+1<n && nums[i]==nums[i+1]){
                    nums[i]=INT_MAX;
                    i++;
                }
            }
            if(i+1<n && nums[i]==nums[i+1]) freq++;
            else freq=1;
            i++;
        }
        sort(nums.begin(),nums.end());;
        int cnt=count(nums.begin(),nums.end(),INT_MAX);
        int sz=n-cnt;
        nums.resize(sz);
        return nums;
    }
};