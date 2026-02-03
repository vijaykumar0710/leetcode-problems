class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=-1,q=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                p=i-1;
                break;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
               q=i+1;
               break;
            }
        }
        if(p!=-1 && q!=-1 && p>0 && q<n-1 && p<q){
            for(int i=p;i<q;i++){
                if(nums[i]<=nums[i+1]) return false;
            }
        }
        else return false;
        return true;
    }
};