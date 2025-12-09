class Solution {
public:
    const int M=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp1,mp2;
        long long ans=0;
        for(auto &num:nums) mp2[num]++;
         for(int j=0;j<n;j++){
             if(mp2.count(nums[j])){
                 mp2[nums[j]]--;
                 if(mp2[nums[j]]==0){
                     mp2.erase(nums[j]);
                 }
             }
             long long val1=nums[j];
             long long val2=val1*2;
             long long cnt1=0;
             if(mp1.count(val2)){
                 cnt1=mp1[val2];
             }
             long long cnt2=0;
             if(mp2.count(val2)){
                 cnt2=mp2[val2];
             }
             ans=(ans+(cnt1*cnt2)%M)%M;
             mp1[nums[j]]++;
         }
        return (int)ans;
    }
};