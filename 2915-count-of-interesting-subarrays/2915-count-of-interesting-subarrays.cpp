class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
       int n=nums.size();
       vector<int>is_dividible;
       for(int i=0;i<n;i++){
        if(nums[i]%m==k) is_dividible.push_back(1);
        else is_dividible.push_back(0);
       }
       long long cnt=0;
       long long sum=0;
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        sum+=is_dividible[i];
        int r1=sum%m;
        if(r1<0) r1+=m;
        if(r1==k) cnt++;
        int r2=(r1-k+m)%m;
        if(mp.count(r2)) cnt+=mp[r2];
        mp[r1]++;
       }
       return cnt;
    }
};