class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       for(int i=0;i<n;i++){
        int x=nums[i];
        int y=target-x;
        for(int j=i+1;j<n;j++){
            if(nums[j]==y){
                return {i,j};
            }
        }
       }
       return {};
    }
};