class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int>basis;
        int res=0;
        for(auto &x:nums){
           for(int b:basis) x=min(x,b^x);
           if(x>0) basis.push_back(x);
        }
        for(auto b:basis) res=max(res,res^b);
        return res;
    }
};