class Solution {
public:
unordered_map<int,int>mp;
int f(vector<int>&start,vector<int>&endi,int &target,int op){
    auto it1=upper_bound(start.begin(),start.end(),target);
    auto it2=lower_bound(endi.begin(),endi.end(),target);
    int x=it1-start.begin();
    int y=it2-endi.begin();
    int cnt=mp.count(target)?mp[target]:0;
    int freq=min(op+cnt,(x-y));
    return freq; 
}
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size(),res=0;
        sort(nums.begin(),nums.end());
        vector<int>start,endi;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
        start.push_back(nums[i]-k);
        endi.push_back(nums[i]+k);
       }
       vector<int>candi;
       for(int i=0;i<n;i++){
        candi.push_back(nums[i]-k);
        candi.push_back(nums[i]+k);
        candi.push_back(nums[i]);
       }
        for(int t=0;t<candi.size();t++){
            res=max(res,f(start,endi,candi[t],numOperations));
        }
        return res;
    }
};