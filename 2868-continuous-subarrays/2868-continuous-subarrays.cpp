class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        multiset<long long>ms;
        long long subarray_cnt=0;
        int i=0;
        for(int j=0;j<n;j++){
            ms.insert(nums[j]);
            while(*ms.rbegin()-*ms.begin()>2){
                ms.erase(ms.find(nums[i]));
                i++;
            }
            subarray_cnt+=(j-i+1);
        }
        return subarray_cnt;
    }
};