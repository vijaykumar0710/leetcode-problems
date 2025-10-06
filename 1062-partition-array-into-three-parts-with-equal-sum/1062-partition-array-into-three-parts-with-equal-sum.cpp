class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        cout<<total;
        if(total%3!=0) return false;
        int target=total/3;
        int sum1=0,sum2=0,sum3=0;
        int i=0;
        while(i<n){
            sum1+=nums[i];
            i++;
            if(sum1==target) break;
        }
        if(i>=n) return false;
        while(i<n){
            sum2+=nums[i];
            i++;
            if(sum2==target) break;
        }
        if(i>=n) return false;
        while(i<n){
            sum3+=nums[i];
            i++;
        }
        if(sum1==sum2 && sum2==sum3) return true;
        return false;
    }
};