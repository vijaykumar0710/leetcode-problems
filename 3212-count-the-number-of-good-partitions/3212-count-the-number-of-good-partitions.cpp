class Solution {
public:
typedef long long ll;
const int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n=nums.size();
        ll cnt=1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;
        int j=mp[nums[0]];
        for(int i=0;i<n;i++){
            if(i>j) cnt=(cnt*2)%M;
            j=max(j,mp[nums[i]]);
        }
        return cnt%M;
    }
};