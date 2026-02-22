class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        bool flag1=true,flag2=false;
        int diff=0;
        for(int i=0;i<n;i++){
           if(nums[i]%2==1){
            flag1=!flag1;
            flag2=!flag2;
           }
           if((i+1)%6==0){
            flag1=!flag1;
            flag2=!flag2;
           }
           if(flag1) diff+=nums[i];
           else diff-=nums[i];
        }
        return diff;
    }
};