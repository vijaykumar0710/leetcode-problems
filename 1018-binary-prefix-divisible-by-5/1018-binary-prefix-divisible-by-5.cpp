class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>res;
        int num=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) num=(2*num)%5;
            else num=(2*num+1)%5;
            if(num==0) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};