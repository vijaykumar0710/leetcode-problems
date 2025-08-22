class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]++;
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           int r1=sum%k;
           if(r1<0) r1+=k;
           int r2=(r1+k)%k;
           if(mp.count(r2)) cnt+=mp[r2];
           mp[r1]++;
        }
        return cnt;
    }
};