class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int majority1=NULL,majority2=NULL;
        for(int i=0;i<n;i++){
            if(nums[i]==majority1) cnt1++;
            else if(nums[i]==majority2) cnt2++;
            else if(cnt1==0){
                majority1=nums[i];
                cnt1=1;
            }else if(cnt2==0){
                majority2=nums[i];
                cnt2=1;
            }else{
                cnt1--,cnt2--;
            }
        }
        vector<int>res;
        cnt1=0,cnt2=0;
        for(auto num:nums){
            if(num==majority1) cnt1++;
            else if(num==majority2) cnt2++;
        }
        if(cnt1>floor(n/3)) res.push_back(majority1);
        if(cnt2>floor(n/3)) res.push_back(majority2);
        return res;
    }
};