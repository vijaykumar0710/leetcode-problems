class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int res=0;
        for(auto &x:nums){
           if(!st.count(x) && x>0) res+=x;
           st.insert(x);
        }
        return res;
    }
};