class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int>bits(32,0);
        for(auto &x:nums){
            for(int i=31;i>=0;i--){
                if(!(x&(1<<i))) continue;
                if(!bits[i]){ bits[i]=x;break; }
                x^=bits[i];
            }
        }
        int res=0;
        for(int i=31;i>=0;i--) res=max(res,res^bits[i]);
        return res;
    }
};