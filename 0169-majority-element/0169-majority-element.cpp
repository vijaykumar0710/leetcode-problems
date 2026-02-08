class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int majority=NULL;
        for(int i=0;i<n;i++){
            if(nums[i]==majority) cnt++;
            else if(cnt==0){
                majority=nums[i];
                cnt=1;
            }else cnt--;
        }
        return majority;
    }
};