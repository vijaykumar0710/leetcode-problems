class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int>basis;
        for(auto &x:nums){
            for(auto b:basis) x=min(x,x^b);
            if(x>0) basis.push_back(x);
        }
        int res=0;
        for(auto &b:basis) res=max(res,b^res);
        return res;
    }
};