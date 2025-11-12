class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>res;
        res=nums;
        for(auto x:nums) res.push_back(x);
        return res;
    }
};