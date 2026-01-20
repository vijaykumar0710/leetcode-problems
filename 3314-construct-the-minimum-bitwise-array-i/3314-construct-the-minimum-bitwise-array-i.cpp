class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            for(int num=0;num<=10000;num++){
                if((num|(num+1))==nums[i]){
                    ans[i]=num;
                    break;
                }
            }
        }
        return ans;
    }
};