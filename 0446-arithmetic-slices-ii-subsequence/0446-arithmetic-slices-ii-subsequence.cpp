typedef long long ll;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        vector<unordered_map<ll,int>>mp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
              ll diff=(ll)nums[i]-nums[j];
              if(mp[j].find(diff)!=mp[j].end()) res+=mp[j][diff];
              mp[i][diff]+=(mp[j][diff]+1);
            }
        }
        return res;
    }
};