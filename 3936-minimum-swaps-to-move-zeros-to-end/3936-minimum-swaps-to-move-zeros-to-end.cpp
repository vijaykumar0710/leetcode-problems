class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt_zero=count(nums.begin(),nums.end(),0);
        int n=nums.size(),res=0;
        int i=n-cnt_zero;
        while(i<n){
            if(nums[i]!=0) res++;
            i++;
        }
        return res;
    }
};