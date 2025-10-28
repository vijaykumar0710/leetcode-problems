class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int prefix_sum=0,res=0;
        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
            if(nums[i]==0){
               if((total-prefix_sum)==prefix_sum) res+=2;
               else if(abs((total-prefix_sum)-prefix_sum)==1) res++;
            }
        }
        return res;
    }
};