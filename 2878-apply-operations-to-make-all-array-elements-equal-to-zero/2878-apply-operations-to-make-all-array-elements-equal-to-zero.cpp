class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        int curr_add=0;
        vector<int>diff(n+1,0);
        for (int i = 0; i < n; i++) {
        curr_add += diff[i];

        nums[i] += curr_add;
        if(nums[i]<0) return false;
        if (nums[i] != 0) {
        if (i + k > n) return false;

        int delta = -nums[i]; // amount to add in range [i..i+k-1]
        curr_add += delta;
        diff[i + k] -= delta; // rollback after k steps
        nums[i] = 0;
         }
       }
       return true;
    }
};