class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st;
        for(auto &x:nums) st.insert(x);
        vector<int>vec;
        for(auto &x:st) vec.push_back(x);
        sort(vec.rbegin(),vec.rend());
        vector<int>res;
        for(int i=0;i<k && i<vec.size();i++) res.push_back(vec[i]);
        return res;
    }
};