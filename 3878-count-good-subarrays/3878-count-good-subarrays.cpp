class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>last_seen(31,-1);
        vector<int>left_bad(n,-1);
        for(int i=0;i<n;i++){
         for(int j=0;j<31;j++){
            if((nums[i]&(1<<j))==0){
                if(last_seen[j]!=-1) left_bad[i]=max(last_seen[j],left_bad[i]);
            }
            else last_seen[j]=i;
         }
        }
        last_seen.assign(31,-1);
        vector<int>right_bad(n,n);
       for(int i=n-1;i>=0;i--){
         for(int j=0;j<31;j++){
            if((nums[i]&(1<<j))==0){
                if(last_seen[j]!=-1) right_bad[i]=min(last_seen[j],right_bad[i]);
            }
            else last_seen[j]=i;
         }
        }
      long long res=0;
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++){
        int idx=-1;
        if(mp.count(nums[i])) idx=mp[nums[i]];
        int left=max(left_bad[i],idx);
        res=(long long)res+1LL*(i-left)*(right_bad[i]-i);
        mp[nums[i]]=i;
      }
      return res;
    }
};