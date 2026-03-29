class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int idx1=-1,idx2=-1;
        int res=101;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && idx2!=-1){
               res=min(res,abs(i-idx2));
            }else if(nums[i]==2 && idx1!=-1){
               res=min(res,abs(i-idx1));
            }
            if(nums[i]==1) idx1=i;
            else if(nums[i]==2) idx2=i;
        }
        return res==101?-1:res;
    }
};