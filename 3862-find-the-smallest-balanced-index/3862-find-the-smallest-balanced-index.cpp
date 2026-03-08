class Solution {
public:
const int M=1e9+7;
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>p(n,0);
        p[0]=nums[0];
        for(int i=1;i<n;i++) p[i]=(p[i-1]+nums[i])%M;
        long long pro=1;
        int res=-1;
        for(int i=n-1;i>0;i--){
         if(pro==p[i-1]) res=i;
         pro=(1LL*pro%M*nums[i]%M)%M;
        }
        return res;
    }
};